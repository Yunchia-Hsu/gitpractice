/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:44:02 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/15 18:06:58 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

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
/*
int main()
{
    char src[] = "0123456789";
    //memmove(src + 2, src, sizeof(char)*5);
    ;
    //printf("original: %s\n", memmove(((void *)0), ((void *)0), 5)); 
    char src2[] = "0123456789";
    //ft_memmove(src2 + 2, src2, sizeof(char)*5);
    printf("ft_: %s\n", ft_memmove(((void *)0), ((void *)0), 5));  
    return (0);
}
*/
/*
// define data type should add () --> ((unsigned char *)dst)
	[back]  not (unsigned char *)dst[back]
*/