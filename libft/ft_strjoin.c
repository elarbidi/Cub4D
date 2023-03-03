/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:18:59 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:52:51 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*allc;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	allc = (char *)malloc(sizeof(char) * (len));
	if (!allc)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(allc + j++) = *(s1 + i++);
	}
	i = 0;
	while (*(s2 + i))
	{
		*(allc + j++) = *(s2 + i++);
	}
	*(allc + j) = '\0';
	return (allc);
}
/*
int main()
{
	char *str = ft_strjoin("", "ddd");
	printf("the result : %s" ,str);
	return 0;
}*/
