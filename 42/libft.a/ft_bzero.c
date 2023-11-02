/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:47 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 20:27:27 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
 
 void   ft_bzero(void *s, size_t n)
 {
    size_t  i;
    char *str; 
    
    str = (char *) s;
    if (n == 0)
        return;
    
    i = 0;
        while(i < n)
        {
            str[i] = 0;
            i++;
        }
        return;
 }
/*
 int main(void)
{
    
    char str[] = "hivers";
    ft_bzero(str,3);
    //printf("ft: %s!\n", ft_bzero(str, 8));
    printf("ft: %s!\n", str);
    
    char str2[] = "hivers";
     //printf("original: %s!\n", bzero(str2, 8));
    bzero(str2, 3);
    printf("ft: %s!\n", str2);
    
    
}
*/

