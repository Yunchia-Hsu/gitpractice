/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:31 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 15:37:47 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//not more than len characters are searched.  Characters that 
//appear after a `\0' character are not searched.  Since the
//strnstr() function is a FreeBSD specific API, it should 
//only be used when portability is not a concern.
#include "libft.h"

//#include <stdio.h>
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack[i] && !needle[i])
		return ((char *)haystack);
	if (len < ft_strlen(needle))
		return (NULL);
	if (!needle[i] || len < 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && i <= (len - ft_strlen(needle)))
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char haystack[] = "A happy day!";
    char needle[] = "day";
    char *result = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
    printf("original: %s\n", result);

    char haystack2[] = "A happy day!";
    char needle2[] = "day";
    char *result2 = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
    printf("ft: %s\n", result2);
}
*/