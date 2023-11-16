/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:00:41 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 09:53:20 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (! s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int main()
{
    char s[] = "-2147djklwno @#$%";
    int fd = 1;
    ft_putendl_fd(s, fd);
    ft_putstr_fd("bees", fd);
}
*/