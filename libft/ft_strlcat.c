/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:39:03 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:29:24 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>*/

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*src1;

	src1 = (char *)src;
	j = ft_strlen(src1);
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (j + dstsize);
	i = 0;
	while (i < dstsize - 1 - len && src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + j);
}
/*
int main(){
	char dst[50] = "a";
	char dst2[50] = "a";
	int i = strlcat(dst, "lorem ipsum dolor sit amet",15);
	int j = ft_strlcat(dst2,"lorem ipsum dolor sit amet",15);
	printf("%s size => %d\n",dst,i);
	printf("%s size => %d",dst2,j);
}
*/
