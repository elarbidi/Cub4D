/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:28:01 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 07:48:11 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n && *str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/*
#include <stdio.h>
int main () {
   char str1[0];
   char str2[0];
   int re;
   int res;


   re = strncmp(str1, str2, 50);
	res = ft_strncmp(str1, str2, 60);
	printf("[%d][%d]", re,res);

   return(0);
}
*/
