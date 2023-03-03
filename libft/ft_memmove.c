/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:50:02 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/17 05:15:07 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		lent;

	lent = 0;
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		lent = len - 1;
		while (lent >= 0 && (dst || src))
		{
			*(unsigned char *)(dst + lent) = *(unsigned char *)(src + lent);
			--lent;
		}
	}
	return (dst);
}
/*

int main ()
{
	char str[50] = "AABBCC";
	char strk[50] = "AABBCC";
	return 0;
}
*/
