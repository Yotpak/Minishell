/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:42:59 by tbalci            #+#    #+#             */
/*   Updated: 2023/07/07 23:34:06 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	result;

	a = 0;
	result = 0;
	sign = 1;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = sign * -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = (result * 10) + (str[a] - '0');
		a++;
	}
	return (result * sign);
}
