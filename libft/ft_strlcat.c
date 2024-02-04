/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:45:50 by tbalci            #+#    #+#             */
/*   Updated: 2023/07/15 09:55:25 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	dstsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (!dst && !size)
		return (0);
	if (dstsize + 1 < size)
	{
		while (dstsize + i < size - 1 && src[i])
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		dst[dstsize + i] = '\0';
	}
	if (dstsize + i >= size)
		dstsize = size;
	return (dstsize + srcsize);
}
