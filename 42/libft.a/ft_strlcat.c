

#include <string.h>
#include <stdio.h>
//#include "libft.h"
int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

size_t ft_strlcat(char * dst, const char * src, size_t dstsize)
{
    size_t  i;
    size_t  dstlength;
    size_t  srclength;

    dstlength = ft_strlen(dst);
    srclength = ft_strlen(src); 
    i = 0;
    if (dstsize == 0)
    {
        return (srclength);
    }
    if (dstsize - 1 < dstlength)//if dont add this condition then it will return (src + n)
    {
        return (srclength + dstsize);
    }
    else
    {
        while (src[i] != '\0' && (dstlength + i) < dstsize - 1)
        {
            dst[dstlength + i] = src[i];
            i++;
        }
        dst[dstlength + i] = '\0';
    } 
    return (dstlength + srclength);
}

int main() 
{
    char dest[11] = "123456";
    char src[] = "789";

    size_t new_length = strlcat(dest, src,2);

    printf("original: %s\n", dest);  // output "Hello, World!"
    printf("New length: %zu\n", new_length);  // output 13 (string length，include \0)

    
    char dest2[11] = "123456";
    char src2[] = "789";

    size_t new_length2 = ft_strlcat(dest2, src2, 2);
    printf("New length2: %lu\n", new_length2);
    printf("Combined ft: %s\n", dest2);
    return 0;
    
}
