/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:15 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/26 12:37:17 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include <stdio.h>
//#include <ctype.h>

int ft_isalnum(int c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (1);
    }
    else
        return (0);
}
/*
int main(void)
{
    int c;

    c = 'g';
    printf("ft: %d\n", ft_isalnum(c));
    printf("original: %d", isalnum(c));

}
*/