/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:44:02 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:05:30 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	size_t				back;

	i = 0;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i < len)
		{
			back = len - i - 1;
			((unsigned char *)dst)[back] = ((const unsigned char *)src)[back];
			i++;
		}
	}
	return (dst);
}
