/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:05 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/26 12:37:09 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int ft_atoi(const char *str)
{
    int i;
    int neg;
    int result;

    result = 0;
    neg = 1;
    i = 0;
    if (str[i] != '-' && (str[i] > '9' || str[i] < '0'))
    {
        return (0);
    }
    if (str[i] == '-')
    {
         if (str[i + 1] == '+')
            return (0);
        neg = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result * neg);    
}
/*int main()
{
    char str[] = "123";
    char str1[] = "3&4567";
    char str2[] = "3&4567";
    printf("str : %d\nstr1 : %d\nstr2 : %d\n", ft_atoi(str),atoi(str1),ft_atoi(str2));
}*/