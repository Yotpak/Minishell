/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 02:21:57 by tbalci            #+#    #+#             */
/*   Updated: 2023/07/08 02:53:18 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*str;
	size_t	i;

	i = 1;
	s = (char *)dst;
	str = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (str < s)
	{
		while (i <= len)
		{
			s[len - i] = str[len - i];
			i++;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
