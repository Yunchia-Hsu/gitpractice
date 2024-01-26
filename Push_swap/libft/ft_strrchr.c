/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:22:54 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:08:20 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = ft_strlen(s);
	while (s[slength] != (char)c)
	{
		if (slength == 0)
			return (NULL);
		slength--;
	}
	return ((char *)s + slength);
}
