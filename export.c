/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:04:32 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/20 19:32:13 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exportinit(t_lexer *lst, char **env)
{
	int	i;
	int	j;
 	t_env *tmp;

	j = dp_wc(env);
	i = 0;
	while (lst->s_env && j > i)
	{
		ft_llstadd_back(&(lst->s_env), ft_llstnew(ft_strdup(env[i])));
		i++;
	}
	i = 0;
	tmp = lst->s_env;
	while (tmp && j > i)
	{
		printf("%s\n",tmp->cmd);
		if (tmp->next != NULL)
			tmp = tmp->next;
		i++;
	}
}

void	ft_export(t_lexer *lst, char **env)
{
	exportinit(lst, env);
}

