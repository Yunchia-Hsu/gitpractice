#include <stdio.h>

long ft_atol(const char *str)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;

    while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
            str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
			i++;
	    if (str[i] == '-' || str[i] == '+')
		{	
			if (str[i] == '-')
				sign = -1;	
			i++;
		}
        if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i]- 48);
		i++;
	}
	return (n * sign);
}

int main ()
{
    char *s = " 45678945311 ";
    printf("%ld\n",ft_atol(s));
}