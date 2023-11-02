/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:24:34 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/01 10:50:47 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
//The memcpy() function copies n bytes from memory area src to memory area dst.  If dst and src overlap,
//behavior is undefined.  Applications in which dst and src might overlap should use memmove(3) instead.//
void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    i = 0;
    const unsigned char   *after_src;
    unsigned char   *after_dst;

    if(dst == src || n == 0)
        return NULL; //behavior not defined
    
    after_src = src;
    after_dst = dst;
    while (i < n)
    {
        after_dst[i] = after_src[i];
        i++;
    }
    return (dst);
}

int main(void)
{
    /*
    char  dst[6] = "hivers";
    char  src[6] = "123456";
    
    ft_memcpy(dst, src, 5);
    
    printf("ft: %s\n", dst);
    */
    char dst2[6] = "hivers";
    char src2[6] = "123456";
    printf("address before: %p\n", src2);
    printf("original: %s\n", memcpy(dst2, src2, 5));
    printf("address dst: %p\n", dst2);
    printf("address src: %p\n", src2);
    return (0);
    
}