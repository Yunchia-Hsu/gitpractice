/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:54:21 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 12:45:05 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bytes long.

#include <string.h>
#include <stdio.h>


int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t  i;
    unsigned char *str1;   
    unsigned char *str2;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
     
    i = 0;
    //compare every unit 
    //while(i < n && (i < s2len || i < s2len))
    while(i < n)
    {
        if(str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    
    }
    return (0);
}

int main()
{
    char s1[] = "1234";
    char s2[] = "123";
    printf("%d\n", memcmp(s1 , s2 , 3));
    printf("%d\n", memcmp(s1 , s2 , 5));
    printf("%d\n", memcmp(s2 , s1 , 5));

    char s3[] = "1234";
    char s4[] = "123";
    printf("ft: %d\n", ft_memcmp(s3 , s4 , 3));
    printf("ft: %d\n", ft_memcmp(s3 , s4 , 5));
    printf("ft; %d\n", ft_memcmp(s4 , s3 , 5));
}