/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:18:17 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 16:18:00 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}
/*
void printBezero(char *str , int n)
{
	int i = 0;
	while (i < n)
	{
		write(1, str, 1);
		str++;
		i++;
	}
}

int main(){
	char str[50] = "this is test";
	ft_bzero(str +3 , 0);
	printBezero(str,13);

}
*/
