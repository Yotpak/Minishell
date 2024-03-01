
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
	t_env	*tmp;

	tmp = list_exlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

char	*ft_exportdup(char *s)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 3));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j[s] != '\0')
	{
		i[str] = j[s];
		if (j[s] == '=')
			str[++i] = '"';
		if (j[s + 1] == '\0')
			str[++i] = '"';
		i++;
		j++;
	}		
	i[str] = '\0';
	return (str);
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

char	*ft_kirkayak(char *split, t_lexer *lst)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	lst->extraline = 0;
	while (split[i])
	{
		if (split[i] == '=')
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		lst->extraline++;
		return (ft_exportdup(split));
	}
	else
	{
		lst->extraline++;
		return (ft_strdup(split));
	}
}

t_env	*ft_exportcontrol(char **split, t_lexer *lst)
{
	(void)lst;
	t_env *extralist;
	int	i;
	int	j;

	j = dp_nl(split);
	i = 2;
	if (j > 1)
		extralist = list_exnew(split[1]);
	while (split[i])
	{
		list_exadd_back(&extralist, list_exnew(ft_strdup(split[i])));
		i++;
	}
	
	// lst->extraflag = 1;
		// if (ft_isalpha(split[i][0]) == 0)
			// printf("bash: export: `%c': not a valid identifier\n",split[i][0]);
	return (extralist);
}