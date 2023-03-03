/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:46:09 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/17 05:04:16 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (dst || src))
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src++);
		i++;
	}
	return (dst);
}
/*
int main()
{
	int arr[50];
	//ft_memcpy(arr +2, arr , sizeof(char) *7);
	int arr2[50];
    ft_memcpy(NULL, NULL, sizeof(char) *7);
    int j = 0;
	int i = 0;
	while(arr[i]){
		printf("[%d]" ,arr[i]);
		i++;
	}
	printf("\n");
	while(arr2[j]){
        printf("[%d]", arr2[j]);
        j++;
    }
	int test;
	int *ptr = &test;
	//printf("[%lu],[%lu],[%lu]", sizeof(ptr), sizeof(char *), sizeof(int *));
}*/
