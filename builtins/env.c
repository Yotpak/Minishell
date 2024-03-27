/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:21:25 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/27 05:32:07 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_lexer *lst) // tmp'Yi kullanıp freelicek bir fonskiyon yaz
{
	t_env	*tmp;

	tmp = lst->s_extra;
	while (tmp != NULL)
	{
		printf("%s\n",tmp->cmd);
		tmp = tmp->next;
	}
}