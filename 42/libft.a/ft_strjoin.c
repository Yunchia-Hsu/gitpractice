/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:07:47 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/01 14:38:18 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int s1_len = ft_strlen(s1);
    int s2_len = ft_strlen(s2);
    char *result;

    result = malloc(s1_len + s2_len + 1);
    if (s1 == '\0')
        return NULL;
    i = 0;
    while(i < s1_len + 1)//strlcpy(result, s1, s1_len + 1 )
    {
        result[i] = s1[i];
        i++;
    }
    i = 0;
    while(i < s2_len + 1)//strlcat(result, s2, (s1_len + s2_len + 1) )
    {
        result[s1_len + i] = s2[i];
        i++;
    } 
    return (result);
}

int main()
{
    char const *s1 =  "happy ";
    char const *s2 = "coding place";
    printf("%s\n", ft_strjoin(s1, s2));
}