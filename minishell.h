/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:19:21 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/08 01:07:30 by tbalci           ###   ########.fr       */
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

// ◦ cd with only a relative or absolute path

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
	
	char	**d_exp;
	t_env	*s_extra; //en başta env ile tanımlanıyor export a argüman gelirse exportta ekleme yapılıyor
	t_env	*s_env; //export'un argümanla gelmiş hallerini export için tutan fonksiyon
	int		echoflag;
	int		exitcode;
	int		exitflag;
	int		envline;
	int		extraflag;
}				t_lexer;

void	ft_echo(t_lexer *lst, char **commands);
int		fn_echo(t_lexer *lst, char *command);
void	ft_pwd(t_lexer *lst);
void	ft_env(t_lexer *lst);
void	ft_exit(t_lexer *lst, char **commands);
void	ft_deneme(t_lexer *lst, char *read_line, char **env);
void	ft_export(t_lexer *lst, char **split);
void	ft_unset(t_lexer *lst, char **split);
void	ft_cd(t_lexer *lst, char **split);

//utils

void unset_utils(t_env **begin_list, char *split, int (*cmp)());
void	ft_echo_print(t_lexer *lst, char **commands);
int		ft_strcmp(char *s1, char *s2);
int		dp_nl(char **s);//bunlardan birini silcem galiba
int		dp_wc(char **s);
void	list_exadd_back(t_env **lst, t_env *new);
void	sort_export(t_env *list);
t_env	*list_exnew(char *content);
t_env	*list_exlast(t_env *lst);
void	ft_exportcontrol(char **split, t_lexer *lst);
char	*dupfunc(char *split, t_lexer *lst);
char	*ft_exportdup(char *s);
int		couplecontrol(t_lexer *lst, char *split);

#endif