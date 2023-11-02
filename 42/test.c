
#include <string.h>
#include <stdio.h>
int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

int main() 
{
    char dest[11] = "abcdefg";
    char src[] = "123";

    size_t new_length = strlcat(dest, src, 3);

    printf("original: %s\n", dest);  // output "Hello, World!"
    printf("New length: %zu\n", new_length);  // output 13 (string length，include \0)

    
    char dest2[11] = "abcdefg";
    char src2[] = " 123";

    size_t new_length2 = ft_strlcat(dest2, src2, 3);
    printf("New length2: %lu\n", new_length2);
    printf("Combined ft: %s\n", dest2);
    return 0;
    
}


#include <string.h>

char *strchr(const char *s, int c);

The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  The termi-
     nating null character is considered to be part of the string; therefore if c is `\0', the functions locate the terminat-
     ing `\0'.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character, or NULL if the character does not appear
     in the string.