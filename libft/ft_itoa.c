/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:37:35 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 03:25:45 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	numdigits(int n)
{
	int		length;
	long	count;
	long	tmp;

	tmp = n;
	length = 0;
	count = 1;
	if (n == 0)
		return (1);
	if (tmp < 0)
	{
		tmp *= -1;
		length++;
	}
	while (count <= tmp)
	{
		length++;
		count *= 10;
	}
	return (length);
}

static long	rev(int n)
{
	long	res;
	long	tmp;

	tmp = n;
	res = 0;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 0)
	{
		res *= 10;
		res = res + (tmp % 10);
		tmp /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		size;
	char	*allc;
	int		i;

	size = numdigits(n);
	tmp = rev(n);
	allc = (char *)malloc(sizeof(char) * (size + 1));
	if (!allc)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		*allc = '-';
		i = 1;
	}
	while (i <= size - 1)
	{
		*(allc + i++) = '0' + (tmp % 10);
		tmp /= 10;
	}
	*(allc + i) = '\0';
	return (allc);
}
/*
#include <limits.h>

int main()
{
	char test[50] = "elarbidi";
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s", ft_itoa(INT_MIN));
	return (0);
}
*/
