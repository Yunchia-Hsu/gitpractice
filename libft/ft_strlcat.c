/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 10:23:11 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
//#include <stdio.h>
//#include <strings.h>


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlength;
	size_t	srclength;

	i = 0;
	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	if (dstsize < dstlength + 1)
		return (srclength + dstsize);
	else
	{
		while (src[i] != '\0' && (dstlength + i + 1) < dstsize)
		{
			dst[dstlength + i] = src[i];
			i++;
		}
		dst[dstlength + i] = '\0';
	}
	return (dstlength + srclength);
}
/*
int main() 
{
    //char *dst[] = NULL;
    char src[] = "789";

   // size_t new_length = strlcat(dest, src,0);

    printf("original: %lu\n", strlcat(NULL, src,0));  // output "Hello, World!"
    // printf("New length: %zu\n", new_length);  
	// output 13 (string length，include \0)

    
    //char *dst2[] = NULL;
    char src2[] = "789";

    size_t new_length2 = ft_strlcat(NULL, src2, 0);
    printf("New length2: %lu\n", new_length2);
    // printf("Combined ft: %s\n", dest2);
    return 0;
    
}
*/

