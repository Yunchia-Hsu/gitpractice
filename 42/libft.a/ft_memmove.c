/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:44:02 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/27 16:27:43 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    int back;

    i = 0;
    if (dst < src)
    {
        while(i < len)
        { 
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    else
    {
        
        while(i < len)
        {
            back = len - i - 1; 
            ((unsigned char *)dst)[back] = ((unsigned char *)src)[back]; // define data type should add () --> ((unsigned char *)dst)[back]  not (unsigned char *)dst[back]
            i++;
        }
    }
    return (dst);
}
/*
int main()
{
    char src[] = "0123456789";
    memmove(src + 2, src, sizeof(char)*5);
    
    printf("original: %s\n", src); 
    char src2[] = "0123456789";
    //ft_memmove(src2 + 2, src2, sizeof(char)*5);
    printf("ft_: %s\n", ft_memmove(src2 + 2, src2, sizeof(char)*5));  
    return (0);
}
*/