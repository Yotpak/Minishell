/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copypaste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:31:50 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/23 20:27:02 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_export(t_env *list)
{
	t_env	*export1;
	t_env	*export2;
	char		*tmp;

	export1 = list;
	tmp = 0;
	while (export1)
	{
		export2 = export1->next;
		while (export2)
		{
			if (ft_strcmp(export1->cmd, export2->cmd) > 0)
			{
				tmp = export1->cmd;
				export1->cmd = export2->cmd;
				export2->cmd = tmp;
			}
			export2 = export2->next;
		}
		export1 = export1->next;
	}
}

// void	ft_export(t_lexer *lst, char **env)
// {
// 	t_env *list;
// 	int	i;

// 	i = 1;
// 	list = malloc(sizeof(t_env));
// 	list->cmd = ft_strdup(env[0]);
// 	while (lst->envline > i)
// 	{
// 		list_exadd_back(&list, list_exnew(ft_strdup(env[i])));
// 		i++;
// 	}
// 	i = 0;
// 	// sort_export(list);
// 	while (lst->envline > i)
// 	{
// 		printf("declare -x %s\n",list->cmd);
// 		list = list->next;
// 		i++;
// 	}
// 	system("leaks minishell");
// }


void	ft_export(t_lexer *lst, char **env)
{
	t_env *list;
	t_env *tmp;
	int	i;

	i = 1;
	list = malloc(sizeof(t_env));
	list->cmd = ft_strdup(env[0]);
	while (lst->envline > i)
	{
		list_exadd_back(&list, list_exnew(ft_strdup(env[i])));
		i++;
	}
	i = 0;
	sort_export(list);
	while (lst->envline > i)
	{
		printf("declare -x %s\n",list->cmd);
		tmp = list;
		list = list->next;
		free(tmp->cmd); // cmd için ayrılan belleği serbest bırak
		free(tmp); // list elemanı için ayrılan belleği serbest bırak
		i++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:29:49 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/23 19:36:47 by tbalci           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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
		{
			j++;
		}
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
		{
			j++;
		}
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

t_env	*list_exnew(char *content)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->cmd = content;
	lst->next = NULL;
	return (lst);
}

void	list_exadd_back(t_env **lst, t_env *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	list_exlast(*lst)->next = new;
}


t_env	*list_exlast(t_env *lst)
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
