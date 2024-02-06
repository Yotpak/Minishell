/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:26 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/05 19:34:59 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_deneme(t_lexer *lst, char *read_line, char **env)
{
	char **split;
	(void)env;
	split = ft_split(read_line, ' ');
	if ((ft_strcmp(split[0], "echo") == 0))
		ft_echo(lst, split);
	// else if (split[0] == "cd")
	// 	ft_cd(split);
	else if ((ft_strcmp(split[0], "pwd")) == 0)
		ft_pwd(lst);
	// else if (split[0] == "export")
	// 	ft_export(split);
	// else if (split[0] == "unset")
	// 	ft_unset(split);
	else if ((ft_strcmp(split[0], "env")) == 0)
		ft_env(lst, env);
	else if ((ft_strcmp(split[0], "exit")) == 0)
		ft_exit(lst, split);
	// else
	// 	ft_execve(split);
	free_split(split);
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
		free(read_line);
    }
    return 0;
}
