/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:21 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/04 18:25:14 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>//silinecek
#include <stdlib.h> // lstaddback new 
#include <unistd.h>
#include "./libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

// echo with option -n
// ◦ cd with only a relative or absolute path
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options
typedef struct s_lexer	
{
	int	echoflag;
}				t_lexer;

// t_lexer	*ft_lstnew(void *content);
void	ft_deneme(t_lexer *lst, char *read_line, char **env);
void	ft_echo(t_lexer *lst, char **commands);
int		fn_echo(t_lexer *lst, char *command);
void	ft_pwd(t_lexer *lst);
void	ft_deneme(t_lexer *lst, char *read_line, char **env);
void	ft_echo_print(t_lexer *lst, char **commands);


#endif