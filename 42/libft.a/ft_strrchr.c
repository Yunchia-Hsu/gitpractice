/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:22:54 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/30 18:18:44 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <string.h>
 #include <stdio.h>

//The strrchr() function is identical to strchr(), except it locates the last occurrence of c.
int ft_strlen(const char *c)
{
    int i;

    i = 0;
    while(c[i] != '\0')
        i++;
    return(i);
}

char   *ft_strrchr(const char *s, int c)
{
    int i;
    int slength;

    i = 1;
    slength = ft_strlen(s);
    if (*s == '\0')
        return (NULL);
    while( slength > 0  && s[slength] != c)
        slength--;
    return((char *)s + slength);
}
 
 int main()
{
    char test[15] = "#23#hjk#&bnhappy";
    char * result = strrchr(test, '#');
    //result[1] = '+';
    //printf("%s\n", test);
    printf("original: %s\n", result);
    printf("%p\n", test+ 7);
    printf("%p\n", result);


    char test2[15] = "#23#hjk#&bnhappy";
    char * result2 = ft_strrchr(test2, '#');
    printf("ft: %s\n", result2);  
}