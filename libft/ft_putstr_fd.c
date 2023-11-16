/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:43:04 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 09:57:19 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (! s)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
/*
int main()
{
    char s[] = "-2147djklwno @#$%";
    int fd = 1;
    ft_putstr_fd(s, fd);
    write (fd , "\n", 1);
}*/