/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:29:49 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/20 19:38:00 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_lexer	*ft_lstnew(void *content)
// {
// 	t_lexer	*lst;

// 	lst = malloc(sizeof(t_lexer));
// 	if (!lst)
// 		return (NULL);
// 	lst->command = content;
// 	lst->next = NULL;
// 	return (lst);
// }

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i]-s2[i]);
}

int	dp_wc(char **s)
{
	int	word_number;
	int	i;
	int	j;

	j = 0;
	i = 0;
	word_number = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\0' && s[i][j] == ' ')
			j++;
		while (s[i][j])
		{
			while (s[i][j] != '\0' && s[i][j] != ' ')
				j++;
			word_number++;
			while (s[i][j] != '\0' && s[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (word_number);
}

int	dp_nl(char **s)
{
	int	word_number;
	int	i;
	int	j;

	j = 0;
	i = 0;
	word_number = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\0' && s[i][j] == '\n')
			j++;
		while (s[i][j])
		{
			while (s[i][j] != '\0' && s[i][j] != '\n')
				j++;
			word_number++;
			while (s[i][j] != '\0' && s[i][j] == '\n')
				j++;
		}
		i++;
	}
	return (word_number);
}
t_env *ft_llstnew(char *cmd)
{
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return NULL;
	new_node->cmd = cmd;
	new_node->next = NULL;
	return new_node;
}

// t_env	*sort_list(t_env *lst, int (*cmp)(int, int)) //strcmp
// {
// 	int	swap;
// 	t_env	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->data, lst->next->data)) == 0)
// 		{
// 			swap = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

void ft_llstadd_back(t_env **lst, t_env *new)
{
	t_env *last;

	if (lst)
	{
		if (*lst)
		{
			if(lst)
				last = ft_llstlast(*lst);
			if (last != NULL)
			{
				last->next = new;
			}
			else
			{
				printf("ansjkdlm\n");
				exit(0);
			}
		}
		else
			*lst = new;
	}
}

t_env	*ft_llstlast(t_env *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}




