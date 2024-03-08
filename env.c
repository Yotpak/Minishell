/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:21:25 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/07 16:51:58 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_lexer *lst)
{
	int	i;
	t_env	*tmp;

	i = 0;
	tmp = lst->s_extra;
	while (lst->s_extra != NULL)
	{
		printf("%s\n",lst->s_extra->cmd);
		lst->s_extra = lst->s_extra->next;
	}
	lst->s_extra = tmp;
}