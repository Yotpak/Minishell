/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:44:40 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/05 19:35:17 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_exitcontrol

void	ft_exit(t_lexer *lst, char **commands)
{
	printf("exit\n");
	(void)lst;
	int	i;
	
	i = dp_wc(commands);
	// if (i < 2)
	// {
		
	// }
	// else
	// {
	// 	if (nonnumeric)
	// }
}

