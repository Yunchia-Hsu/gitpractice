/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:41:43 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 10:04:35 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || ! f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void myfunction(unsigned int i, char *c)
{
  
    if (c[i] >= 'a' && c[i] <= 'z')
    {
        *c[i] -= 32;
    }
}

int main()
{
    char   s[] = "12ha2ppy78";
    ft_striteri(s, &myfunction);
    printf("%s\n", s);
    //free(s);
    return 0;
}
*/