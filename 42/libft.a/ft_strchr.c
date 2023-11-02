/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:10:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/30 17:22:34 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
/*The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  The termi-
     nating null character is considered to be part of the string; therefore if c is `\0', the functions locate the terminat-
     ing `\0'.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character, or NULL if the character does not appear
     in the string.
*/
int ft_strlen(const char *str)
{ 
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    //if (i > ft_strlen(s) || (c == 0))
    //    return NULL; 
    if (*s == '\0')
        return (NULL);
    while(s[i] != c && s[i] != '\0')//look for c from s 
        i++;  
    return((char *)s + i);//add (char *) ortherwise  there is mismtch return type const char * and char "      
}

int main()
{
    char test[] = "account @happy";
    char * result = strchr(test, '@');
    //result[1] = '+';
    //printf("%s\n", test);
    printf("original: %s\n", result);
    printf("%p\n", test+ 5);
    printf("%p\n", result);


    char test2[] ="account @happy";
    char * result2 = ft_strchr(test2, '@');
    printf("ft: %s\n", result2);  
}