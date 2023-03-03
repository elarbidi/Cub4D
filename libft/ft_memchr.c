/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:27:38 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:28:40 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		i++;
		tmp++;
	}
	return (NULL);
}
/*
int main()
{
	printf("%s vs %s",ft_memchr("ttt",'k' , 2), memchr("ttt",'k',10));
}*/
