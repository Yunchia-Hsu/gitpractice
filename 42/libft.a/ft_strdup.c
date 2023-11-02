/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:03 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/26 12:38:06 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;     
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strdup(char *s1)
{
    char *dest;
    int length;

    length = ft_strlen(s1);
    dest = (char *) malloc(length * sizeof(char) + 1);
    ft_strcpy(dest, s1);

    if (s1 == '\0')
        return (0);
    return (dest);
}
/*int main()
{
    char *original = "hello hivers!";
    //char *copy = ft_strdup(original);
    printf("%s\n", original);
    printf("%s\n", ft_strdup(original));
}