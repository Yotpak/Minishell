/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:28 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/01 09:47:05 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdbool.h>

int	fn_echo(t_lexer *lst, char *command)
{
	int		i;
	
	i = 0;
	if (command[i++] != '-')
		return (0);
	while (command[i] && command[i] == 'n')
		i++;
	if (command[i] == '\0')
	{
		lst->echoflag = 1;
		return (1);
	}
	return (0);
}

void	ft_echo_print(t_lexer *lst, char **commands)// fileno değişkeni tutulacak pipe varsa oluşan fileno güncellenecek eğer pipe yoksa fileno standart olarak 1 kalacak.
{
	int	i;

	i = 0;
	while (commands[i])
	{
		ft_putstr_fd(commands[i++], 1);
		if (commands[i])
			ft_putchar_fd(' ', 1);
		else if (commands[i] == NULL && lst->echoflag == 0)
			ft_putchar_fd('\n', 1);
	}
}

void	ft_echo(t_lexer *lst, char **commands) // tokenize bir biçimde geldiği varsayılıyor.
{
	int		i;

	lst->echoflag = 0;
	(void)lst;
	i = 1;
	while (commands[i] && fn_echo(lst, commands[i]))
		i++;
	ft_echo_print(lst, &commands[i]);
}