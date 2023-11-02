/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:29:08 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 10:49:16 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

//  The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.

void   *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const char    *result;

    result = s;
    i = 0;
    if (result == NULL || n == 0)
        return NULL;//再s中找c

    while (i < n && result[i] != '\0')
    {
        if(result[i] == c)
            return((void *)result + i);
        i++;
    }
    return NULL;
    //回傳指向c的pointer
}

int main()
{
    char s[] = "david@microsoft.com";
    char    *result = memchr(s, '.', 19);
    printf("%s\n", result);

    char s2[] = "david@microsoft.com";
    char    *result2 = ft_memchr(s2, '.', 19);
    printf("%s\n", result2);
}
