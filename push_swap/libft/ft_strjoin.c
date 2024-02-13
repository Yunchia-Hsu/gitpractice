/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:07:47 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:07:04 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result == '\0')
		return (NULL);
	i = 0;
	while (i < s1_len + 1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len + 1)
	{
		result[s1_len + i] = s2[i];
		i++;
	}
	return (result);
}
