/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:06:29 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/15 09:33:05 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	oldpwd_set(t_lexer *lst)
{
	t_env	*tmp;
	char	*olddir;

	tmp = lst->m_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			olddir = ft_strjoin("OLDPWD=", tmp->var);
			del_same_node_env("OLDPWD=", lst->m_env);
			del_same_node_exp("OLDPWD=", &lst->m_export);
			add_env_export(olddir, lst);
			lst->errorcode = 0;
			free(olddir);
		}
		tmp = tmp->next;
	}
}

static void	upper_dir(t_lexer *lst, char *cwd)
{
	t_env	*tmp;
	char	*newdir;
	char	*slash;

	tmp = lst->m_env;
	slash = ft_substr(cwd, 0, last_slash(cwd));
	newdir = ft_strjoin("PWD=", slash);
	oldpwd_set(lst);
	if (isdir(slash))
		return (cd_errors(lst, isdir(slash), slash));
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			del_same_node_env("PWD=", lst->m_env);
			del_same_node_exp("PWD=", &lst->m_export);
			add_env_export(newdir, lst);
			break ;
		}
		tmp = tmp->next;
	}
	free(slash);
	free(newdir);
	lst->errorcode = 0;
}

static void	cd_to_dir(t_lexer *lst)
{
	t_env	*tmp;
	char	*newdir;
	char	cwd[256];

	tmp = lst->m_env;
	oldpwd_set(lst);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			oldpwd_set(lst);
			newdir = ft_strjoin("PWD=", getcwd(cwd, 256));
			del_same_node_env("PWD=", lst->m_env);
			del_same_node_exp("PWD=", &lst->m_export);
			add_env_export(newdir, lst);
			free(newdir);
			lst->errorcode = 0;
			return ;
		}
		tmp = tmp->next;
	}
}

static void	go_homedir(t_lexer *lst)
{
	t_env	*tmp;
	char	*homedir;

	tmp = lst->m_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "HOME"))
		{
			oldpwd_set(lst);
			homedir = ft_strjoin("PWD=", tmp->var);
			if (isdir(tmp->var))
				return (cd_errors(lst, isdir(tmp->var), tmp->var));
			del_same_node_env("PWD=", lst->m_env);
			del_same_node_exp("PWD=", &lst->m_export);
			add_env_export(homedir, lst);
			free(homedir);
			lst->errorcode = 0;
			return ;
		}
		tmp = tmp->next;
	}
	expander_errors("cd: HOME not set");
	lst->errorcode = 1;
}

void	cd_cmd(t_lexer *lst, t_parser *prs, char **cmd)
{
	char	cwd[256];

	(void)prs;
	if (!cmd[1])
		go_homedir(lst);
	else if (!ft_strcmp(cmd[1], ".."))
		upper_dir(lst, getcwd(cwd, 256));
	else if (!isdir(cmd[1]))
		cd_to_dir(lst);
	else if (!ft_strcmp(cmd[1], "-"))
		go_oldpwd(lst);
	else
		cd_errors(lst, isdir(cmd[1]), cmd[1]);
}

void	go_oldpwd(t_lexer *lst)
{
	t_env	*tmp;
	char	*homedir;

	tmp = lst->m_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "OLDPWD"))
		{
			homedir = ft_strjoin("PWD=", tmp->var);
			if (isdir(tmp->var))
				return (cd_errors(lst, isdir(tmp->var), tmp->var));
			oldpwd_set(lst);
			del_same_node_env("PWD=", lst->m_env);
			del_same_node_exp("PWD=", &lst->m_export);
			add_env_export(homedir, lst);
			free(homedir);
			lst->errorcode = 0;
			return ;
		}
		tmp = tmp->next;
	}
	expander_errors("cd: OLDPWD not set");
	lst->errorcode = 1;
}

int	isdir(const char *filename)
{
	struct stat	file;
	int			is_folder;

	if (filename)
	{
		stat(filename, &file);
		if (!access(filename, F_OK))
		{
			is_folder = S_ISREG(file.st_mode);
			if (is_folder == 0)
			{
				is_folder = chdir(filename);
				if (is_folder == 0)
					return (0);
				else
					return (1);
			}
			else
				return (2);
		}
		else
			return (3);
	}
	return (4);
}

size_t	last_slash(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	while (len > -1)
	{
		if (filename[len] == '/')
		{
			if (len != 0)
				return (len);
			else
				return (len + 1);
		}
		len--;
	}
	return (len);
}
