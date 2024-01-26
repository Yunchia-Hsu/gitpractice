/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:24:34 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:05:17 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*after_src;
	unsigned char			*after_dst;

	i = 0;
	if (dst == src)
		return (NULL);
	after_src = src;
	after_dst = dst;
	while (i < n)
	{
		after_dst[i] = after_src[i];
		i++;
	}
	return (dst);
}
