/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:03 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/15 17:43:09 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strdup(const char	*s1)
{
	char	*dest;
	size_t	length;

	length = ft_strlen(s1);
	dest = (char *) malloc(length * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, length + 1);
	return (dest);
}
/*
int main()
{
    char *original = "hello hivers!";
    
    //printf("%s\n", original);
    printf("%s\n", ft_strdup(original));
}*/