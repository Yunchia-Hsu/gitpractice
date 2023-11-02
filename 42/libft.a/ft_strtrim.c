/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:49 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/02 10:24:21 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(const char *str)
{ 
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

static int ft_if_c_in_set(char c, char const *str)//check if char c matches any of charactor in string str 
{
    int i;

    i = 0;
    while(str[i])
    {   
        if (str[i] == c)
            return (1);
        i++;
    }
    return(0);    
}

char	*ft_strtrim(char const *s1, char const *set) 
{
    int start;
    int end;
    char *result;
    int i;

    start = 0;
    end = ft_strlen(s1);
    while(s1[start] != '\0' && ft_if_c_in_set(s1[start], set) == 1)//check from the start 
        start++;
    
    while(start < end && ft_if_c_in_set( s1[end - 1], set) == 1)//check from the start 
        end--;//check from the end
    result = malloc( end - start + 2);//add memory to result
    if(!result)
        return NULL;
    //ft_memcpy( result, s1 + start, (end - start));
    i = 0;
    while (start < end)//copy string
		result[i++] = s1[start++];
    return (result);
}

int main()
{
    char const *s2 = "!hello helloh!";
    char const *set2 = "!h";
    printf("ft: %s\n", ft_strtrim(s2, set2));
}