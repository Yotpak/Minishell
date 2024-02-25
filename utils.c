
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

t_env *ft_kirkayak(char **split, t_lexer *lst) //export toprak= toprak'i ele alarak düzenlemeye çalışıyorum 
{
	t_env	*extralist;
	int	i;
	char	**str;

	i = 0;
	while (split[i])
	{
		if(split[i] == '=')
			str = ft_split(split, '=');// spliti = e göre ayırırsak toprak="" olmuyor tikaq
		i++;
	}
	i = 1;
	extralist = list_exnew(str[0]);
	lst->extraline = dp_wc(str);
	while (lst->extraline > i)
	{
		list_exadd_back(&extralist, list_exnew(ft_strdup(str[i])));
		i++;
	}
	sort_export(extralist);
	return (extralist);
}

int	ft_lagaluga(t_lexer *lst, char *split)
{
	t_extra	*extralist;

	extralist = list_exnew()











	lst->s_extra = extralist;

}

t_env *ft_exportcontrol(char **split, t_lexer *lst)
{
	t_env *extralist;
	int	i;

	i = 1;
	while (split[i]) // toprak= toprak
	{
		if (ft_isalpha(split[i][0]) == 0)
			printf("bash: export: `%c': not a valid identifier\n",split[i][j]);
		else // toprak=
		{

		}
		i++;
	}
	extralist = ft_kirkayak(split, lst);
	return (extralist);
}