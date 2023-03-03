/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:43:17 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 03:22:10 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
		return (1);
	return (0);
}
/*
int main()
{
	printf("this is the systeme  one => %d\n" , isalpha('1'));
	printf("this is mine => %d" , ft_isalpha('1'));
	return (0);
}
*/	
