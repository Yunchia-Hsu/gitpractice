/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:24:34 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 11:06:15 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memcpy() function copies n bytes from memory area 
//src to memory area dst.  If dst and src overlap,
//behavior is undefined.  Applications in which dst 
//and src might overlap should use memmove(3) instead.

//#include <stdio.h>
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
/*
int main(void)
{
    char  dst[] = "hivers";
    char  src[] = "zyxwvutst";
    
    printf ("ft: %s\n",ft_memcpy(dst, src, 0) );
    printf ("ft_ address dst: %p\n", dst);

    char dst2[] = "hivers";
    char src2[] = "zyxwvutst";
    printf("address before: %p\n", src2);
    printf("original: %s\n", memcpy(dst2, src2, 0));
	
    printf("address dst2: %p\n", dst2);
    printf("address src2: %p\n", src2);
    return (0);  
}
*/