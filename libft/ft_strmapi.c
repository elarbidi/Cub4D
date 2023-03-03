/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:40:33 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/17 05:27:53 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*allc;
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (s)
	{
		while (*(s + size))
			size++;
		allc = (char *)malloc(sizeof(char) * (size + 1));
		if (!allc)
			return (NULL);
		while (i < size)
		{
			*(allc + i) = f(i, *(s + i));
			i++;
		}
		*(allc + i) = '\0';
		return (allc);
	}
	return (NULL);
}
/*
char null(unsigned int i , char s)
{
	return s - i;
}
int main()
{
	char (*f)(unsigned int, char);
	f = null;
	char s[50] = "test";
	char *test = ft_strmapi(s,f);
	printf("%s",test);
}
*/
