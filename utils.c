/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:29:49 by tbalci            #+#    #+#             */
/*   Updated: 2023/12/15 20:33:38 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lstnew(void *content)
{
	t_lexer	*lst;

	lst = malloc(sizeof(t_lexer));
	if (!lst)
		return (NULL);
	lst->command = content;
	lst->next = NULL;
	return (lst);
}
