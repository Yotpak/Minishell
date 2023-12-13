/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:26 by tbalci            #+#    #+#             */
/*   Updated: 2023/12/13 18:31:20 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int ac, char **av, char **env)
{
    char *read_line;


    while (1)
    {
        read_line = readline("minishell> ");
        free(read_line);
		
    }

    return 0;
}
