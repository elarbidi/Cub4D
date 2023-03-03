/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:59:38 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:30:08 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "./libft.h"

static int	checker(const char *s1, const char *n, size_t len)
{
	while (*s1 == *n && *s1 && *n && len > 0)
	{
		if (*(n + 1) == '\0')
			return (1);
		s1++;
		n++;
		len --;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	i = 0;
	if (len == 0 && !*needle)
		return ((char *)haystack);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && len > 0)
	{
		if (checker(haystack + i, needle, len))
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (NULL);
}
/*
int main()
{
	const char *s1 = "lorem ipsum dolor sit amet";
    const char *s2 = "dolor";
    char *ptr;

    ptr = ft_strnstr(s1, s2,0);
	printf("{%s}",ptr);
	
}*/
