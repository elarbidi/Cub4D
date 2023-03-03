/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 05:53:09 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/18 23:22:48 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{
	t_list *s = ft_lstnew("120");
	int i = 5;
	while (i < 5)
	{
		ft_lstadd_front(&s ,ft_lstnew("111"));
		i++;
	}
	printf("%d", i);
}*/
