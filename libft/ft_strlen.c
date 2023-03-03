/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:11:42 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 03:53:19 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "./libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}
/*
int main()
{
	printf("this is  sys => %lu\n" , strlen("anass"));
	printf("this is mine => %lu" , ft_strlen("anass"));
	return 0;
}
*/
