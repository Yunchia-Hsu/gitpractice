/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:50:31 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 14:42:19 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *restrict dst, const char *src, size_t maxsize)
{
	size_t	i;

	i = 0;
	if (maxsize == 0)
	{
		return (ft_strlen(src));
	}
	while ((i < (maxsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int main()
{
    char src[10] ="123456789";
    char dst[15];
	// dst should be the same or bigger than maxsize or it will overflow
    char src2[10] ="123456789";
    char dst2[15];
    strlcpy (dst2, "", 15);
    printf("%s\n", dst2);
    printf("number: %lu\n", strlcpy(dst, "", 15));
    
    
   
    printf("number: %lu\n", ft_strlcpy (dst2, "", 15));
   printf("%s\n", dst);
}
*/