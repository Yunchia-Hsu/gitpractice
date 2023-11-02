/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:19 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 21:22:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//each and returns a pointer to the allocated memory.  The allocated memory is filled with bytes of value
//zero.
#include <stdlib.h>
#include <stdio.h>
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

void *ft_calloc(size_t count, size_t size)
{
    void * pointer; 

    pointer = malloc(count * size);
    if (!pointer)//if pointer is null
        return NULL;
    ft_bzero(pointer, count * size);
    return (pointer);
}
/*
int main()
{
    //for(int i = 0, i < 100;)
    char *pointer;
    pointer = malloc(6 + 1);
    pointer = "12345";
    for (int i = 0; i < 10; i++)
        printf("ma: %c\n", pointer[i]);

    pointer = ft_calloc(6, 1);
    for (int i = 0; i < 10; i++)
        printf("C: %c\n", pointer[i]);
    
    free(pointer);

}
*/
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