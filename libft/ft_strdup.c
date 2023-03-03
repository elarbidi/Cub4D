/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:55:52 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/15 03:31:54 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>*/
#include "./libft.h"

static int	len(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*allc;
	int		i;

	i = 0;
	allc = (char *) malloc(sizeof(char) * (len(s1)+ 1));
	if (allc)
	{
		while (*(s1 + i))
		{
			*(allc + i) = *(s1 + i);
			i++;
		}
		*(allc + i) = '\0';
	}
	else
	{
		return (NULL);
	}
	return (allc);
}

/*
int main() {
0
    const char * original = "The original string.";

    char * copy = ft_strdup( original );
    

    printf( "%s\n", copy );

    free( original );

    return 0;
}*/
