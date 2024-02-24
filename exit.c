/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:44:40 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/24 18:46:47 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_nonnumeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_exitcontrol(t_lexer *lst, char **commmands)
{
	(void)lst;
	int	i;

	i = dp_wc(commmands);
	if (i > 2)
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	lst->exitflag = 0;
	if (i == 2)
	{
		if (ft_nonnumeric(commmands[1]))
		{
			printf("exit\n");
			printf("minishell: exit: %s: numeric argument required\n", commmands[1]);
			return (255);
		}
		else
		{
			printf("exit\n");
			return (ft_atoi(commmands[1]) % 256);
		}
	}
	else
	{
		lst->exitflag = 0;
		printf("exit\n");
		return (0);
	}
	
}

void	ft_exit(t_lexer *lst, char **commands)
{
	(void)lst;
	if (ft_strcmp(commands[0], "exit") == 0)
	{
		lst->exitflag = 1;
		lst->exitcode = ft_exitcontrol(lst, commands);
		if (lst->exitflag == 0)
			exit(lst->exitcode);
		else
			return ;
	}
	else
	{
		printf("minishell: %s: command not found\n", commands[0]);
		lst->exitflag = 127;
		return ;
	}
}

