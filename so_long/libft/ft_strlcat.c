/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:07:15 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlength;
	size_t	srclength;

	i = 0;
	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	if (dstsize < dstlength + 1)
		return (srclength + dstsize);
	else
	{
		while (src[i] != '\0' && (dstlength + i + 1) < dstsize)
		{
			dst[dstlength + i] = src[i];
			i++;
		}
		dst[dstlength + i] = '\0';
	}
	return (dstlength + srclength);
}
