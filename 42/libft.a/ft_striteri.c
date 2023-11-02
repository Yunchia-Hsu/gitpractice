/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:41:43 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/02 14:36:38 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri( char *s,  void (*f)(unsigned int, char*)   )
{
    unsigned int i;

    i = 0;
    while(!s || !f)//check is s and f are NULL
        return;
    while(s[i])
    {
        f( i, s + i);
        i++;
    }
}