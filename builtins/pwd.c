/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:02:00 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/09 17:05:36 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void	ft_pwd(t_lexer *lst)
{
	(void)lst;	
	char	currentpwd[256];
	
	if (getcwd(currentpwd, sizeof(currentpwd)) != NULL)
		printf("%s\n",currentpwd);
}