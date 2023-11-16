/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:29:08 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/15 17:41:36 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The memchr() function locates the first occurrence of c 
//(converted to an unsigned char) in string s.
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	chr;

	result = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (result[i] == chr)
			return (result + i);
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char s[] = "david@microsoft.com";
    char    *result = memchr(s, 2 + 256, 3);
    printf("%s\n", result);

    char s2[] = "david@microsoft.com";
    char    *result2 = ft_memchr(s2, 2 + 256 , 3);
    printf("%s\n", result2);
}
*/