/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:50:29 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 17:20:21 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_length;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if (s_length <= start)
		return (ft_strdup(""));
	if (start + len >= s_length) // if the len + start is greater than s_leng, than just get the s_leng minus start
		len = s_length - start;
	substr = malloc (len * sizeof(char) + 1);
	if (substr == NULL )
		return (NULL);
	while (i < len)
	{
		substr[i] = ((char *)s)[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
int main()
{
    char const *s = "lorem ipsum dolor sit amet";
    char *result;
    int start = 7;
    size_t len =10;
    result =  ft_substr(s, start, len);
    printf("ft: %s\n", result);
    
   
}
*/
