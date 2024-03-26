/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:07:40 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/17 15:07:01 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_home(t_lexer *lst, char *var) // leak potansiyeli olabilir
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