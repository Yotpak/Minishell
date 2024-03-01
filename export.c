/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:31:50 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/01 21:43:21 by tbalci           ###   ########.fr       */
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

void	ft_export(t_lexer *lst, char **env, char **split)
{
	t_env	*list;
	// t_env	*tmp;
	t_env	*extralist;
	// int	extraflag;
	int	i;

	i = 1;
	extralist = ft_exportcontrol(split, lst);
	list = list_exnew(ft_strdup(env[0]));
	while (lst->envline > i)
	{
		list_exadd_back(&list, list_exnew(ft_strdup(env[i])));
		i++;
	}
	i = 0;
	// sort_export(list);
	// while (lst->envline > i)
	// {
	// 	printf("declare -x %s\n",list->cmd);
	// 	tmp = list;
	// 	list = list->next;
	// 	free(tmp->cmd);
	// 	free(tmp);
	// 	i++;
	// }
	// i = 0;
	// if (lst->extraflag == 1)
	// {
	// 	printf("%d\n",lst->extraline);
	// 	while (lst->extraline > i)
	// 	{
	// 		printf("kac\n");
	// 		printf("declare -x %s\n",extralist->cmd);
	// 		tmp = extralist;
	// 		extralist = extralist->next;
	// 		free(tmp->cmd);
	// 		free(tmp);
	// 		i++;
	// 	}
	// }
	while(extralist != NULL)
	{
		printf("%s\n",extralist->cmd);
		extralist = extralist->next;
	}
}
