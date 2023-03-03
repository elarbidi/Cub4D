/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 06:19:47 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/22 00:11:15 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (del)
	{
		node = *lst;
		if (node == NULL)
		{
			free(node);
			lst = NULL;
		}
		if (*lst)
		{
			while (*lst != NULL)
			{
				node = (*lst);
				*lst = (*lst)->next;
				del(node->content);
				free(node);
			}
		}
	}
}
