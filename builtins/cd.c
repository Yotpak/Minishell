/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:06:29 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/17 15:08:57 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_dir(const char *filename)
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

void	set_oldpwd(t_lexer *lst)
{
	t_env	*tmp;
	char	*old;

	tmp = lst->s_extra;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->cmd, "HOME", 4) == 0)
		{
			old = find_home(lst, "HOME");
			del_env_exp(lst, "OLDPWD=");
			list_exadd_back(&lst->s_env, list_exnew(old));
			list_exadd_back(&lst->s_extra, list_exnew(old));
			lst->exitcode = 0;
			free(old);
		}
		tmp = tmp->next;
	}
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
			if (isdir(tmp->var))
				return (cd_errors(lst, isdir(tmp->var), tmp->var));
			del_env_exp(lst, "PWD=");
			add_env_export(home, lst);
			free(home);
			lst->exitcode = 0;
			return ;
		}
		tmp = tmp->next;
	}
	expander_errors("cd: HOME not set");
	lst->exitcode = 1;
}


void	ft_cd(t_lexer *lst, char **split)
{
	(void)split;
	// if (split[1] == NULL) //cd tek girildiyse home'a gidecek
	// {

		set_oldpwd(lst);
	// }
}