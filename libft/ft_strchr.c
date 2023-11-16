/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:10:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 10:34:31 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strchr() function locates the first occurrence of c
(converted to a char) in the string pointed to by s.  The termi-
nating null character is considered to be part of the string; 
therefore if c is `\0', the functions locate the terminat-
ing `\0'.
*/
#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
/*
int main()
{
    char test[] = "account @happy";
    char * result = strchr(test, 'e' + 256);

    printf("original: %s\n", result);
    printf("%p\n", test+ 5);
    printf("%p\n", result);

    char test2[] ="account @happy";
    char * result2 = ft_strchr(test2, 'e' + 256);
    printf("ft: %s\n", result2);  
}
*/