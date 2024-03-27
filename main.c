/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:26 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/27 04:12:45 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	take_env(t_lexer *lst, char **env)
{
	int	i;

	i = 0;
	lst->equal = 0;
	lst->envline = dp_nl(env);
	lst->s_env = NULL;
	lst->s_extra = NULL;
	lst->d_exp = malloc(sizeof(char *) * (dp_nl(env) + 1));
	while (env[i])
	{
		list_exadd_back(&lst->s_extra, list_exnew(env[i]));	
		lst->d_exp[i] = ft_exportdup(env[i], lst);
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	ft_deneme(t_lexer *lst, char *read_line, char **env)
{
	char **split;
	(void)env;
	split = ft_split(read_line, ' ');
	if (split == NULL)
		return ;
	if ((ft_strcmp(split[0], "echo") == 0))
		ft_echo(lst, split);
	else if (ft_strcmp(split[0], "cd") == 0)
		ft_cd(lst, split);
	else if ((ft_strcmp(split[0], "pwd")) == 0)
		ft_pwd(lst);
	else if ((ft_strcmp(split[0], "export")) == 0)
			ft_export(lst, split);
	else if ((ft_strcmp(split[0], "unset")) == 0)
		ft_unset(lst, split);
	else if ((ft_strcmp(split[0], "env")) == 0)
		ft_env(lst);
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
	take_env(lst, env);

    while (1)
    {
        read_line = readline("minimini-->");
		ft_deneme(lst, read_line, env);
		add_history(read_line);	
		free(read_line);
    }
    return 0;
}
