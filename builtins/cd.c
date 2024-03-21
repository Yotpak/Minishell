/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:06:29 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/17 15:08:57 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	gohome(t_lexer *lst)
{
	t_env	*tmp;
	char	*old;

	tmp = lst->s_extra;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->cmd, "HOME", 4) == 0)
		{
			old = find_home(lst, "HOME");
			del_env_exp(lst, "OLDPWD=");
			list_exadd_back(&lst->s_env, list_exnew(old));
			list_exadd_back(&lst->s_extra, list_exnew(old));
			// add_env_exp(lst, old);
			// oldpwd ekle
		}
		tmp = tmp->next;
	}
	tmp = lst->s_extra;
	while (lst->s_extra)
	{
		printf("tmp->cmd = %s\n",lst->s_extra->cmd);
		lst->s_extra = lst->s_extra->next;
	}
}

void	ft_cd(t_lexer *lst, char **split)
{
	(void)split;
	// if (split[1] == NULL) //cd tek girildiyse home'a gidecek
	// {
		gohome(lst);
	// }
}