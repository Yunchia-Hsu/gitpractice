/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:50:29 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/01 11:53:54 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    i = 0;
    const unsigned char   *after_src;
    unsigned char   *after_dst;

    if(dst == src || n == 0)
        return NULL; //behavior not defined
    
    after_src = src;
    after_dst = dst;
    while (i < n){
        after_dst[i] = after_src[i];
        i++;
    }
    return (dst);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char * substr;
    size_t s_length;
    char *src;

    s_length = strlen(s); 
    substr = malloc(len * sizeof(char) + 1);//add len memoring 
    if (substr == NULL )
        return(NULL);
    if (s_length < start || len == 0)
		return (strdup(""));
    if (start <= s_length ) 
    src = (char *)s + start;
    ft_memcpy(substr, src,len); 
        return(substr);
}
/*
char	*og_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (s_len < start)
		return (strdup(""));
	s_len = strlen(s + start);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc (sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	strlcpy(substr, s + start, len + 1);
	return (substr);
}
int main()
{
    char const *s = "0123456789";
    char *result;
    int start = 1;
    size_t len =3;
    result = ft_substr(s, start, len);
    printf("ft: %s!\n", result);
    
    char const *s2 = "0123456789";
    char *result2;
    int start2 = 1;
    size_t len2 = 3;
    result2 = og_substr(s2, start2, len2);
    printf("og: %s!\n", result2);
    return (0);
}
*/