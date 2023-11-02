/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:50:31 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/30 10:32:58 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"


size_t  ft_strlcpy(char * restrict dst, const char * src, size_t maxsize) // 
{
    size_t  strlength;
    size_t i;

    i = 0;
    while(src[i] != '\0')
        i++;
    strlength = i;
    i = 0;
    if (maxsize == 0)
		return (strlength);
    else if(maxsize > strlength + 1)
    {
        while (i < strlength + 1)
        
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    else
    {
        while(i < maxsize - 1)        
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return(strlength);
}

int main()
{
    char src[10] ="123456789";
    char dst[7];// dst should be the same or bigger than maxsize or it will overflow
    char src2[10] ="123456789";
    char dst2[7];
    strlcpy (dst2, src2, 7);
    printf("%s\n", dst2);
    //printf("number: %lu\n", strlcpy (dst2, src2, 6));
    
    
    ft_strlcpy (dst, src,7);
    //printf("number: %lu\n", ft_strlcpy (dst2, src2, 6));
    printf("%s\n", dst);
}