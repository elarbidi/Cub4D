/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:54:47 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/17 05:25:34 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*dest;
	const char	*source;
	size_t		count;

	dest = dst;
	source = src;
	count = dstsize - 1;
	if (count > 0 && dstsize != 0)
	{
		while (count > 0)
		{
			*dest = *source;
			if (*source == '\0')
				break ;
			count--;
			dest++;
			source++;
		}
	}
	if (count == 0)
		if (dstsize != 0)
			*dest = '\0';
	return (len(src));
}
/*
int main()
{
	char src[10] = "elarbidi";
	char dest[10];
	char src2[10] = "elarbidi";
	char dest2[10];
		strlcpy(dest,src,sizeof(char)*5);
	
	printf("[%zu] [%s]",ft_strlcpy(dest2,src2,sizeof(char)* 10) , dest2);
	printf("[%zu] [%s]",strlcpy(dest,src,sizeof(char)* 10) , dest);
	return 0;
}
*/
