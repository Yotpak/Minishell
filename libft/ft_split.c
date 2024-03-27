/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:50:55 by tbalci            #+#    #+#             */
/*   Updated: 2024/03/27 03:04:45 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_deallocate(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(str[j++]);
	free(str);
	return (NULL);
}

static int	pass_char(char const *s, char c, int i)
{
	int	a;

	a = 0;
	if (i)
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
	}
	else
	{
		while (s[a] != '\0' && s[a] != c)
			a++;
	}
	return (a);
}

static int	word_counter(char const *s, char c)
{
	int	word_number;
	int	i;

	i = 0;
	word_number = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		word_number++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (word_number);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_number;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	word_number = word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_number + 1));
	while (i < word_number)
	{
		s = s + pass_char(s, c, 1);
		str[i] = ft_substr(s, 0, pass_char(s, c, 0));
		if (!str)
			return (ft_deallocate(str, word_number));
		s = s + pass_char(s, c, 0);
		i++;
	}
	str[i] = NULL;
	return (str);
}
