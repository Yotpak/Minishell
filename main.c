/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:26 by tbalci            #+#    #+#             */
/*   Updated: 2023/12/15 21:01:55 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char *read_line;
	
	t_lexer *l_l;
	lst = malloc(sizeof(t_lexer));
	
	lst->command = "yokedici";
	printf("--%s\n",lst->command);
    while (1)
    {
        read_line = readline("minimini-->");
    }
    return 0;
}
