/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:11:04 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/22 19:16:50 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit_up(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_putdigit_up(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_putdigit_up(n / base, base);
		if (count == -1)
			return (-1);
		return (count + ft_putdigit_up(n % base, base));
	}
}
