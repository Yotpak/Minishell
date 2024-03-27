/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:07:40 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/27 04:36:06 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_home(t_lexer *lst, char *var)// leak potansiyeli olabilir
{
	t_env	*tmp;
	char	*home;

	tmp = lst->s_extra;
	while (tmp)
	{
		if (ft_strncmp(tmp->cmd, var, 4) == 0)
		{
			home = ft_strjoin("OLDPWD=", &tmp->cmd[5]);
		}
		tmp = tmp->next;
	}
	return (home);
}

// void	add_env_exp(t_lexer *lst, char *old)
// {
// 	t_env	*tmp;
	
// 	tmp = lst->s_extra;
// 	while (tmp)
// 	{
// 		if (ft_strncmp(tmp->cmd, "PWD=", 4))
// 		{

// 		}
// 		tmp = tmp->next;
// 	}
// }


void	del_env_exp(t_lexer *lst, char *var)
{
	t_env	*tmp;

	tmp = lst->s_extra;
	while (tmp)
	{
		if (ft_strncmp(tmp->cmd, var, 7))
		{
			unset_utils(lst, &lst->s_env, var, ft_strncmp);
			unset_utils(lst, &lst->s_extra, var, ft_strncmp);
		}
		tmp = tmp->next;
	}
}

void	ex_error(char *error)
{
	ft_putstr_fd("minikshell$: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

void	cd_error(t_lexer *lst, int flag, char *file)
{
	char	*error;

	error = ft_strjoin("cd: ", file);
	if (flag == 1)
		error = s1free_strjoin(error, ": Permisson denied");
	else if (flag == 2)
		error = s1free_strjoin(error, ": Not a directory");
	else if (flag == 3)
		error = s1free_strjoin(error, ": No such file or directory");
	ex_error(error);
	free(error);
	lst->exitcode = 1;
}

size_t	last_slash(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	while (i > -1)
	{
		if (filename[i] == '/')
		{
			if (i != 0)
				return (i);
			else
				return (i + 1);
		}
		i--;
	}
	printf("last_slash içi = %d\n", i);
	return (i);
}