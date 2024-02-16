/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:49 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:08:32 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if_c_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	if (! s1 || ! set)
		return (NULL);
	while (s1[start] != '\0' && ft_if_c_in_set (s1[start], set) == 1)
		start++;
	while (start < end && ft_if_c_in_set(s1[end - 1], set) == 1)
		end--;
	result = malloc (end - start + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
		result [i++] = s1 [start++];
	result[i] = '\0';
	return (result);
}
