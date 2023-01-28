/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:40 by majmani           #+#    #+#             */
/*   Updated: 2023/01/18 18:17:11 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len_int(int n)
{
	int		count;
	long	c;

	c = n;
	count = 0;
	if (c < 0)
	{
		c = c * -1;
		count++;
	}
	else if (c == 0)
		count++;
	while (c > 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	c;

	c = n;
	j = ft_len_int(n);
	str = malloc(j + 1);
	if (!str)
		return (0);
	str[j] = '\0';
	if (c < 0)
	{
		str[0] = '-';
		c = c * -1;
	}
	j--;
	if (c == 0)
		str[j] = '0';
	while (j >= 0 && c > 0)
	{
		str[j] = (c % 10) + '0';
		c = c / 10;
		j--;
	}
	return (str);
}
