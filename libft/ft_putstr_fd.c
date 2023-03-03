/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:53:22 by aelarbid          #+#    #+#             */
/*   Updated: 2021/11/21 23:25:49 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
	{
		write(fd, s++, 1);
	}
}
/*
int main()
{
	int fd = open("test", O_RDWR |O_CREAT);
	ft_putstr_fd("test" , fd);
	return 0;
}
*/
