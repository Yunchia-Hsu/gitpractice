/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:42:15 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/15 17:25:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
/*
int main()
{
    int fd = 1;
    ft_putnbr_fd(123, fd);
    write (fd , "\n", 1);
    ft_putnbr_fd(-123, fd);
    write (fd , "\n", 1);
    ft_putnbr_fd(-2147483648, fd);
    write (fd , "\n", 1);
    ft_putnbr_fd(10, fd);
    write (fd , "\n", 1);
	
}
*/
