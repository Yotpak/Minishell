/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:05:26 by tbalci            #+#    #+#             */
/*   Updated: 2023/07/19 20:48:52 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lencalculator(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (n <= 9)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	w;
	int		i;

	w = n;
	nlen = lencalculator(n);
	i = nlen;
	str = malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	while (nlen--)
	{
		if (w < 0)
			w = w * -1;
		str[nlen] = (w % 10) + '0';
		w = w / 10;
	}
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}
