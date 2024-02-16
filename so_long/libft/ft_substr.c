/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:50:29 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:10:38 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_length;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if (s_length <= start)
		return (ft_strdup(""));
	if (start + len >= s_length)
		len = s_length - start;
	substr = malloc (len * sizeof(char) + 1);
	if (substr == NULL )
		return (NULL);
	while (i < len)
	{
		substr[i] = ((char *)s)[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
