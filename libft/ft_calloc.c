/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:36:38 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/17 06:57:41 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allc;

	allc = (void *)malloc(size * count);
	if (!allc)
		return (NULL);
	if (allc)
	{
		allc = ft_memset(allc, 0, size * count);
	}
	return (allc);
}
