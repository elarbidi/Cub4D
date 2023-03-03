/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:04:28 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:31:35 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*allc;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		allc = malloc(1);
	else if (ft_strlen(s) - start < len)
		allc = malloc(ft_strlen(s) - start + 1);
	else
		allc = malloc(len + 1);
	if (!allc)
		return (NULL);
	j = 0;
	while (j < len && j + start < ft_strlen(s))
	{
			allc[j] = s[j + start];
			j++;
	}
	allc[j] = '\0';
	return (allc);
}
/*
int main()
{
	char *dset = ft_substr("tripouille", 0, 42000);
	printf("this is the result :%s", dset);
	return 0;
}
*/
