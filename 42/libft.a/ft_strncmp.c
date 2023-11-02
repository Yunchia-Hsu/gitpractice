/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:44 by yhsu              #+#    #+#             */
/*   Updated: 2023/10/31 17:23:57 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
    {
        return(0);
    }
    while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
    {
        i++;
    }
    return (s1[i] - s2[i]);
}
int main(void)
{
    char    s1[] = "happy day";
    char    s2[] = "day";
    
    printf("%i", ft_strncmp(s1, s2, 3));
    return 0;
}