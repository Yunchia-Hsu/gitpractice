/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:44 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 16:31:01 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0') && str1[i] == str2[i] && i < (n - 1))
		i++;
	return (str1[i] - str2[i]);
}
/*
int main(void)
{
    char    s1[] = "happy day";
    char    s2[] = "day";
    
    printf("%i", ft_strncmp("test\200", "test\0", 6));
    return 0;
}*/