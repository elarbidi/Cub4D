/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 04:30:06 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/18 11:59:26 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*(lst) == NULL)
	{
		*lst = new;
	}
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}
/*
int main(int argc, char* argv[])
{
        t_list *root;
		root = ft_lstnew("test");
        ft_lstadd_front(&root, ft_lstnew("kkk"));
		while(root != NULL)
		{
			printf("%s", root->content);
			root = root->next;
		}
	return 0; 
}
*/
