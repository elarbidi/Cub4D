/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:57:53 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 16:17:17 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//

#include "./libft.h"

static int	change(int i)
{
	if (i > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;

	result = 0;
	i = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -i;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
		if (result > 9223372036854775807)
			return (1 * change(i));
	}	
	return ((int)(result * i));
}
/*
int main () {
   int val;
   char str[200];
   
   strcpy(str,  "\t\v\f\r\n \f-06050");
   val = ft_atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);


   return(0);
}*/
