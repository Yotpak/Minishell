/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:31:50 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/07 17:35:13 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dupfunc(char *split, t_lexer *lst)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (split[i])
	{
		if (split[i] == '=')
			flag = 1;
		i++;
	}
	if (flag == 1)
	{	
		list_exadd_back(&lst->s_extra, list_exnew(ft_strdup(split)));
		return (ft_exportdup(split));
	}
	else
		return (ft_strdup(split));
}

void	sort_export(t_env *list)
{
	t_env	*export1;
	t_env	*export2;
	char	*tmp;

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

void	print_list(t_env *list)
{
	t_env	*tmp;

	if (list == NULL)
		return ;
	sort_export(list);
	while (list != NULL)
	{
		printf("declare -x %s\n", list->cmd);
		tmp = list;
		list = list->next;
	}
}

void	ft_exportcontrol(char **split, t_lexer *lst)
{
	int		i;
	int		j;
	char	*value;

	j = dp_nl(split);
	i = 1;
	while (split[i] && j > i)
	{
		if (ft_isalpha(split[i][0]) == 0)
			printf("bash: export: `%s': not a valid identifier\n", split[i]);
		else
		{
			if (couplecontrol(lst, split[i]) == 1)
			{
				value = dupfunc(split[i], lst);
					if (value != NULL)
						list_exadd_back(&lst->s_env, list_exnew(value));
			}
		}
		i++;
	}
	lst->extraflag = 1;
}

void	ft_export(t_lexer *lst, char **split) //exportun verileri bu fonksiyondan çıkarken freelnmiyor.
{
	int		i;
	int		j;

	i = 0;
	j = dp_nl(split);
	if (j == 1)
	{
		while (lst->envline > i)
		{
			printf("declare -x %s\n", lst->d_exp[i]);
			i++;
		}
	}
	
	if (j > 1)
		ft_exportcontrol(split, lst);
	if (lst->extraflag == 1 && j == 1)
		print_list(lst->s_env);
}
