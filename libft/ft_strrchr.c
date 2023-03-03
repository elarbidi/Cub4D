/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:18:31 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/18 23:57:42 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)str;
	while (*(tmp + i))
		i++;
	if (c == '\0')
		return (tmp + i);
	i--;
	while (*(tmp + i) && i > 0)
	{
		if (*(tmp + i) == (char)c)
			return (tmp + i);
		i--;
	}
	if (*(tmp + i) != (char)c)
		return (NULL);
	return (tmp + i);
}
/*
#include <stdio.h>
#include <string.h>

int main () 
{
   char *ret;

   ret = ft_strrchr("tnktnt", 'a');

   printf("|%s|\n|%s|",ret ,strrchr("tnktnt",'a'));
   return(0);
}*/
