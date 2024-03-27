/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:06:29 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/27 05:39:21 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_and_change_dir(const char *filename)
{
	if (filename)
	{
		if (!access(filename, F_OK))
		{
			if (!chdir(filename))
				return (0);
			else
				return (1);
		}
		else
			return (2);
	}
	return (3);
}

void	set_oldpwd(t_lexer *lst) // hazır
{
	t_env	*tmp;
	char	*old;

	tmp = lst->s_extra;
	while (tmp != NULL)
	{
		if(ft_strncmp(tmp->cmd, "PWD", 3) == 0)
		{
			old = ft_strjoin("OLDPWD=", &tmp->cmd[5]);
			del_env_exp(lst, "OLDPWD=");
			printf("old = %s\n",old);
			list_exadd_back(&lst->s_env, list_exnew(old));
			list_exadd_back(&lst->s_extra, list_exnew(old));
			lst->exitcode = 0;
			free(old);
		}
		tmp = tmp->next;
	}
}


static void	upper_dir(t_lexer *lst, char *cwd)
{
	t_env	*tmp;
	char	*new;
	char	*slash;

	tmp = lst->s_extra;
	slash = ft_substr(cwd, 0, last_slash(cwd));
	new = ft_strjoin("PWD=", slash);
	set_oldpwd(lst);
	if (check_and_change_dir(slash))
		return (cd_error(lst, check_and_change_dir(slash), slash));
	while (tmp)
	{
		if (ft_strncmp(tmp->cmd, "PWD", 3) == 0)
		{
			del_env_exp(lst, "PWD=");
			list_exadd_back(&lst->s_env, list_exnew(new));
			list_exadd_back(&lst->s_extra, list_exnew(new));
			break ;
		}
		tmp = tmp->next;
	}
	free(slash);
	free(new);
	lst->exitcode = 0;
}

void	go_home(t_lexer *lst)
{
	t_env	*tmp;
	char	*home;

	tmp = lst->s_extra;
	while (tmp)
	{
		if (ft_strncmp(tmp->cmd, "HOME", 4) == 0)
		{
			set_oldpwd(lst);
			home = ft_strjoin("PWD=", &tmp->cmd[5]);
			if (check_and_change_dir(&tmp->cmd[5]))
				return (cd_error(lst, check_and_change_dir(&tmp->cmd[5]), &tmp->cmd[5]));
			del_env_exp(lst, "PWD=");
			list_exadd_back(&lst->s_env, list_exnew(home));
			list_exadd_back(&lst->s_extra, list_exnew(home));
			free(home);
			lst->exitcode = 0;
			return ;
		}
		tmp = tmp->next;
	}
	ex_error("cd: HOME not set");
	lst->exitcode = 1;
}

void	ft_cd(t_lexer *lst, char **split)
{
	char	cwd[256];

	if (!split[1])
	{
		go_home(lst);
	}
	else if (!ft_strcmp(split[1], ".."))
		upper_dir(lst, getcwd(cwd, 256));
	// else if (!check_and_change_dir(split[1]))
	// 	cd_to_dir(lst);
	// else if (!ft_strcmp(split[1], "-"))
	// 	go_oldpwd(lst);
	// else
	// 	cd_errors(lst, check_and_change_dir(split[1]), split[1]);
}