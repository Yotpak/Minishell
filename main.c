/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:26 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/04 19:57:32 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	ft_deneme(t_lexer *lst, char *read_line, char **env)
{
	char **split;
	split = ft_split(read_line, ' ');
	if ((ft_strncmp(split[0], "echo", 4) == 0)) // strcmp qullan.<<
		ft_echo(lst, split);
	// else if (split[0] == "cd")
	// 	ft_cd(split);
	else if (read_line[0] == 'P' && read_line[1] == 'W' && read_line[2] == 'D')
		ft_pwd(lst, split, env);
	// else if (split[0] == "export")
	// 	ft_export(split);
	// else if (split[0] == "unset")
	// 	ft_unset(split);
	// else if (split[0] == "env")
	// 	ft_env(split);x
	// else if (split[0] == "exit")
	// 	ft_exit(split);
	// else
	// 	ft_execve(split);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char *read_line;
	
	t_lexer *lst;
	lst = malloc(sizeof(t_lexer));
    while (1)
    {
        read_line = readline("minimini-->");
		ft_deneme(lst, read_line, env);
		add_history(read_line);
		if (read_line[0] == 'e' && read_line[1] == 'x')
			break;
    }
    return 0;
}
