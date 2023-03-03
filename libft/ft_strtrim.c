/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 03:23:31 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 17:42:19 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	search(const char *set, char key)
{
	while (*set)
	{
		if (*(set) == key)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*allc;
	int		end;
	int		start;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) && search(set,*(s1 + start)))
		start++;
	while (end > start && search(set,*(s1 + end - 1)))
		end--;
	allc = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!allc)
		return (NULL);
	while (start < end)
	{
		*(allc + i) = *(s1 + start++);
		i++;
	}
	*(allc + i) = '\0';
	return (allc);
}
/*
int main()
{
	char	*tst = ft_strtrim("          "," ");
//	if (!strcmp(ret, s2))
	printf("%s",tst);
	//free(tst);
	//printf("%lu" ,*(0x7feb38402a70));
//	system("leaks a.out");
	//check_leaks();
}*/		
