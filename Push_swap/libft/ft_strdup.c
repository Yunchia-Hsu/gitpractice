/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:03 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:06:52 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*dest;
	size_t	length;

	length = ft_strlen(s1);
	dest = (char *) malloc(length * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, length + 1);
	return (dest);
}
