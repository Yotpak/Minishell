/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:21:25 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/15 09:30:42 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_lexer *lst) // tmp'Yi kullanıp freelicek bir fonskiyon yaz
{
	t_env	*tmp;

	tmp = lst->s_extra;
	sort_export(lst->s_extra);
	while (lst->s_extra != NULL)
	{
		printf("%s\n",lst->s_extra->cmd);
		lst->s_extra = lst->s_extra->next;
	}
	lst->s_extra = tmp;
}