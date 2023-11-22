/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:29 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/22 18:20:46 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_format(char c, va_list args);
int	ft_putp(unsigned long n);
int	ft_putdigit_up(long n, int base);
int	ft_putdigit(long n, int base);
int	ft_putstr(const char *s);
int	ft_putchar(char c);

#endif