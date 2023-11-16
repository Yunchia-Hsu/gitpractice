/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:22:54 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 16:02:53 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strrchr() function is identical to strchr(),
//except it locates the last occurrence of c.
#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = ft_strlen(s);
	while (s[slength] != (char)c)
	{
		if (slength == 0)
			return (NULL);
		slength--;
	}
	return ((char *)s + slength);
}
/*
 int main()
{
    char test[15] = "";
    char * result = strrchr(test, '\0');
    //result[1] = '+';
    //printf("%s\n", test);
    printf("original: %s\n", result);
    printf("%p\n", test+ 7);
    printf("%p\n", result);


    char test2[15] = "happy";
    char * result2 = ft_strrchr(test2, 's');
    printf("ft: %s\n", result2);  
}
 */