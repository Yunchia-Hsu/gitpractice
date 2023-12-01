
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
size_t	ft_strlcpy(char *restrict dst, const char *src, size_t maxsize)
{
	size_t	i;

	i = 0;
	if (maxsize == 0)
	{
		return (strlen(src));
	}
	while ((i < (maxsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}



char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

int main()
{
    char test[] = "account @happy";
    char * result = strchr(test, 'h' + 256);

    printf("original: %s\n", result);
    printf("%p\n", test+ 5);
    printf("%p\n", result);

    char test2[] ="account @happy";
    char * result2 = ft_strchr(test2, 'h' + 256);
    printf("ft: %s\n", result2);  
}