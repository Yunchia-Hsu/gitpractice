/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:26:19 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 15:04:23 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_i_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = len + 1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	void	ft_itoa_int(int n, char *str, int *i)
{
	if (n >= 10)
	{
		ft_itoa_int(n / 10, str, i);
		ft_itoa_int(n % 10, str, i);
	}
	else
	{
		str[*i] = n + '0';
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(ft_i_len(n) * sizeof(char) + 1);
	if (! result)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		n = n * -1;
	}
	if (n == -2147483648)
	{
		result[i++] = '2';
		n = 147483648;
	}
	ft_itoa_int (n, result, &i);
	result[i] = '\0';
	return (result);
}
/*
int main()
{
    printf("%s\n", ft_itoa(123));
    printf("%s\n", ft_itoa(-456));
    printf("%s\n", ft_itoa(-2147483648));
}
*/