/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 02:07:17 by tbalci            #+#    #+#             */
/*   Updated: 2023/07/08 02:21:18 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t m)
{
	char	*str;
	char	*s;
	size_t	i;

	i = 0;
	str = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (0);
	while (i < m)
	{
		str[i] = s[i];
		i++;
	}
	return (dst);
}
