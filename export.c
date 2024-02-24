/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:31:50 by tbalci            #+#    #+#             */
/*   Updated: 2024/02/24 18:45:57 by tbalci           ###   ########.fr       */
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
// 	t_env	*list;
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
// 	sort_export(list);
// 	while (lst->envline > i)
// 	{
// 		printf("declare -x %s\n",list->cmd);
// 		list = list->next;
// 		i++;
// 	}
// }


void	ft_export(t_lexer *lst, char **env)
{
	t_env *list;
	t_env *tmp;
	int	i;

	i = 1;
	list = list_exnew(ft_strdup(env[0]));
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
		free(tmp->cmd);
		free(tmp);
		i++;
	}

}

