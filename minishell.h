/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:21 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/25 00:53:50 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h> 
# include <unistd.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// echo with option -n
// ◦ cd with only a relative or absolute path
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options

typedef struct s_extra
{
	char			*cmd;
	struct s_extra	*next;
}				t_extra;

typedef struct s_env
{
	char			*cmd;
	struct s_env	*next;
}				t_env;

typedef struct s_lexer
{
	t_env	s_env;
	t_extra	s_extra;
	int		echoflag;
	int		exitcode;
	int		exitflag;
	int		envline;
	int		extraflag; // for export extras
	int		extraline; // ''    ''     ''
}				t_lexer;

// t_lexer	*ft_lstnew(void *content);
void	ft_echo(t_lexer *lst, char **commands);
int		fn_echo(t_lexer *lst, char *command);
void	ft_pwd(t_lexer *lst);
void	takenv(t_lexer *lst, char **env);
void	ft_env(t_lexer *lst, char **env);
void	ft_exit(t_lexer *lst, char **commands);
void	ft_deneme(t_lexer *lst, char *read_line, char **env);
void	ft_echo_print(t_lexer *lst, char **commands);
void	ft_export(t_lexer *lst, char **env, char **split);
void	sort_export(t_env *list);

void	ft_init(t_lexer *lst, char **env);

//utils

int		ft_strcmp(char *s1, char *s2);
int		dp_nl(char **s);
int		dp_wc(char **s);
void	list_exadd_back(t_env **lst, t_env *new);
t_env	*list_exnew(char *content);
t_env	*list_exlast(t_env *lst);
t_env	*ft_exportcontrol(char **split, t_lexer *lst);
t_env *ft_kirkayak(char **split, t_lexer *lst); //export toprak= toprak'i ele alarak düzenlemeye çalışıyorum 

#endif