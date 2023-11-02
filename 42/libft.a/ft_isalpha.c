/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:22 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/02 10:01:50 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
#include <stdio.h>
int	ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ))
    {
        return (1);
    }
    else
        return (0);
}
/*
int main ()
{
    
    int c = 'G';
    printf("isalpha is : %d\n", isalpha(c));
    printf("ft is : %d", ft_isalpha (c));
}
*/