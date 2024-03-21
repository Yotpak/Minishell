/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:12:10 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/17 15:04:23 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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

char	*ft_exportdup(char *s, t_lexer *lst)
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
		{
			lst->equal = j;
			str[++i] = '"';	
		}
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

int	couplecontrol(t_lexer *lst, char *split)
{
	int		flag;
	int		i;
	t_env	*tmp;

	flag = 1;
	tmp = lst->s_env;
	while (lst->s_env != NULL)
	{
		i = 0;
		while (lst->s_env->cmd[i] && split[i])
		{
			if (split[i] == lst->s_env->cmd[i])
			{
				if (split[i] == '=' && split[i + 1] != '\0')
				{
					flag = 0;
					break ;
				}
			}
			else
				break;
			i++; 
		}
		lst->s_env = lst->s_env->next;
	}
	lst->s_env = tmp;
	return (flag);
}