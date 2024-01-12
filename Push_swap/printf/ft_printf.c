/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:56:12 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/22 19:19:39 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar('%');
	else if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putdigit((long)va_arg(args, int), 10);
	else if (c == 'u')
		count += ft_putdigit((long)va_arg(args, unsigned int), 10);
	else if (c == 'x')
		count += ft_putdigit((long)va_arg(args, unsigned int), 16);
	else if (c == 'X')
		count += ft_putdigit_up((long)va_arg(args, unsigned int), 16);
	else if (c == 'p')
		count += ft_putp((unsigned long) va_arg(args, long));
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format || *format == '\0')
		return (0);
	va_start (args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format (*(++format), args);
		else
			count += write (1, format, 1);
		if (count == -1)
			return (-1);
		++format;
	}
	va_end(args);
	return (count);
}
