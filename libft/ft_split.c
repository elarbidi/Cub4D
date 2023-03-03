/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:58:21 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/22 05:23:25 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "./libft.h"

static int	wordscount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[0] != c)
	{
		count++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	*cu_strdup(char *s, char c)
{
	char	*allc;
	int		i;
	int		j;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	allc = (char *)malloc((i +1) * sizeof(char));
	if (!allc)
		return (NULL);
	j = 0;
	while (j < i && *(s + j) != c)
	{
		*(allc + j) = *(s + j);
		j++;
	}
	*(allc + j) = '\0';
	return (allc);
}

char	**cus_free(char **allc)
{
	int	i;

	i = 0;
	while (allc[i])
		free(allc[i++]);
	free(allc);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**allc;
	int		lenw;

	if (!s)
		return (NULL);
	lenw = wordscount(s, c);
	allc = (char **)malloc(sizeof(char *) *(lenw + 1));
	if (!allc)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			allc[i++] = cu_strdup(s, c);
			if (!allc[i - 1])
				return (cus_free(allc));
		}
		while (*(s + 1) && *s != c)
			s++;
		s++;
	}
	allc[i] = 0;
	return (allc);
}
/*
int main()
{
	//char *tab[];
	int i = wordscount("        " , ' ');
	
//	char **tab = ft_split("       " ,' ');
//	while (*tab)
//	{
//		printf("%s\n", *tab);
//		tab++;
//	}
//	int j = 0;
//	while (tab[j])
//		free(tab[j]);
//	free(tab);
	printf("%d", i);
//	system("leaks a.out");
}*/
