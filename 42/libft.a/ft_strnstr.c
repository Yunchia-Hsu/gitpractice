/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:31 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 18:09:26 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//not more than len characters are searched.  Characters that appear after a `\0' character are not searched.  Since the
//strnstr() function is a FreeBSD specific API, it should only be used when portability is not a concern.
#include <string.h>
#include <stdio.h>
#include "libft.h"
int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
    {
        return(0);
    }
    while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i = 0;
    size_t  j = 0;
    int n_length; 

    n_length = ft_strlen(needle);
    if (len == 0)
        return NULL;
    if (needle[0] == '\0')
        return ((char *)haystack);
    while (haystack[i] != '\0' && n_length <= len)
    {   
        if (haystack[i] != needle[j])
            i++;
        if (ft_strncmp(haystack + i, needle, n_length)== 0)//needle is the same as a part of haystack
            return((char *)&haystack[i]);
        j++;
        
    }
    return(NULL);
}

int main()
{
    char haystack[] = "A happy day!";
    char needle[] = "day";
    char *result = strnstr(haystack, needle, 13);
    printf("original: %s\n", result);

    char haystack2[] = "A happy day!";
    char needle2[] = "day";
    char *result2 = ft_strnstr(haystack2, needle2, 13);
    printf("ft: %s\n", result2);
}