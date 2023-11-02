/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:36:50 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/26 17:20:55 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.
#include <stdio.h>
//#include <string.h>

void    *ft_memset(void *b, int c, size_t len)
{
    char	*str;
	size_t	i;

	str = b;
    i = 0;
    while (i < len)
    {
        str[i] = c;
        i++;
    }
    return b;
}
/*
int main(void)
{
    char str[] = "hivers";
    ft_memset(str, '0', 3);
    printf("%s\n", str);
}
*/


