/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:19 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 08:48:06 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//each and returns a pointer to the allocated memory. 
//the allocated memory is filled with bytes of value zero.
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}
/*
int main(void)
{
    int i;
    char *ptr;

    i = 0;
    ptr = ft_calloc(6, 1);
    while (i < 6)
    {
        if (ptr[i] == '\0')
            printf(" 0 ");
        else
            printf(" 1 ");
        i++;
    }
    return 0;
}
*/