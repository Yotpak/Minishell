/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:21:25 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/20 19:17:04 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	takenv(t_lexer *lst, char **env)
// {
// 	int	i;

// 	i = 0;
// 	lst->s_env.cmd = malloc(sizeof(char *) * dp_nl(env));
// 	while (env[i])
// 	{
// 		lst->s_env.cmd[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// }

// void	ft_env(t_lexer *lst, char **env)
// {
// 	takenv(lst, env);
// 	int	i;

// 	i = 0;
// 	while (lst->s_env.cmd[i])
// 	{
// 		printf("%s\n", lst->s_env.cmd[i]);
// 		i++;
// 	}
// }