/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:49:11 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/17 04:27:26 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void unset_utils(t_lexer *lst, t_env **begin_list, char *split, int (*cmp)())
{
	t_env	*tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return;
	tmp = *begin_list;
	if (cmp(tmp->cmd, split, lst->equal) == 0)
	{
		*begin_list = tmp->next;
		free(tmp);
		unset_utils(lst, begin_list, split, cmp);
	}
	else
	{
		tmp = *begin_list;
		unset_utils(lst, &tmp->next, split, cmp);
	}
}

void	ft_unset(t_lexer *lst, char **split)
{
	int	i;

	i = 1;
	while (split[i])
	{
		if (ft_isalpha(split[i][0]) == 0)
			printf("-bash: unset: `%s': not a valid identifier\n", split[i]);
		else
		{
			unset_utils(lst, &lst->s_env, split[i], ft_strncmp);
			unset_utils(lst, &lst->s_extra, split[i], ft_strncmp);
		}
		i++;
	}
}