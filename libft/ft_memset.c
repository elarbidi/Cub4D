/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:18 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 03:29:20 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	//memset(str + 13, '.', 8*sizeof(char));
	printf("memset = > %s" ,memset(str + 13, '.', 8*sizeof(char)));
	char str2[50] = "GeeksForGeeks is for programming geeks.";
	//ft_memset(str2 + 13, '.', 8*sizeof(char));
	printf("\nft_memset => %s", ft_memset(str2 + 13, '.', 8*sizeof(char)));
	return 0;
}
*/
