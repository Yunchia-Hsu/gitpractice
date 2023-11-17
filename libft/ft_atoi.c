/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:07:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 16:07:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	check_long(long number, int digit)
{
	long long	llong_max;

	llong_max = 9223372036854775807;
	if (number > llong_max / 10)
		return (1);
	else if (number * 10 > llong_max - digit)
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (((str[i] == '+') || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign = 0;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		if (check_long(result, str[i] - '0'))
			return (sign * -1);
		result = result * 10 + (str[i++] - '0');
	}
	if (! sign)
		result = result * -1;
	return (result);
}
/*
void ft_atoi_test(int num_test) // 21
{
	
	char *str[]  = {"+5481237" , 
		"-5481237",
		"2147483647", //MAX_INT = 2**31 -1
		"2147483648", // 10(MAX_INT/10 ) + 8
		"2147483649", // 10(MAX_INT/10 ) + 9
		"-2147483649",
		"-2147483647",
		"-2147483648",  // =MIN_INT
		"-2147483650",  // =MIN_INT - 2
		" 13421772800",  //  sing is not channging for 32 signed int
		"-12789479812379481",
		"12789479812379481",
		"203458024385908220934850234523452349433405523",
		"-10923480912809514850932830941802938481028304810280384",
		"-109234809128095148509328309418029384810283048102
		803111273498729317498237914723981749817239847198237
		49818723981742393871498233748905634702282374109823740172
		38974902730149827340917203947102938370496570439834732908162501239874109823784",
		"9223372036854775809",  // LLONG_MAX + 2
		"9223372036854775808",  // LLONG_MAX + 1
		"9223372036854775807",  // LLONG_MAX
		"9223372036854775800", // LLONG_MAX - 7
		"-9223372036854775809",  // LLONG_MIN -1
		"-9223372036854775808",  // LLONG_MIN
		"-9223372036854775807",  // LLONG_MIN +1
		"-9223372036854775800", // LLONG_MIN + 8
		"5764607523034234880", //>>> 2**62 + 2**60
		"63410682753376583680", // (2**62+2**60 +2**59)*10
		"-63410682753376583680", // (2**62+2**60 +2**59)*10
		"-63410682753376583687", // (2**62+2**60 +2**59)*10 + 7
		"\0"};
	int	i = 0;
	int answ_true;
	int answ_ft;
	int count = 0;
	long long  max_long64;
	long num = 5764607523034234880;
	long long  llong_max_10 = ((unsigned long long)(-1))/2/10;

	printf("START Test %d - atoi\n\n", num_test);


//	max_long64 = ((unsigned long)(-1))/2;
//	printf("max long long = ? = %lld\n", max_long64);
//	printf("max long long / 10 = %lld\n", llong_max_10);

	while (*str[i] != '\0')
	{
		answ_true = atoi(str[i]);
		answ_ft = ft_atoi(str[i]);
		if (answ_true != answ_ft || 0)  // 0-> 1 for printing all
		{
			printf("string =%s\n", str[i]);
			printf("atoi=%d\n", answ_true);
			printf("ft=%d\n\n", answ_ft);
			count++;
		}
		i++;
	}
	if (!count)
		printf("atoi OK\n\n");
	else
		printf("atoi KO\n\n");
}

int	main(void)
{
	ft_atoi_test(21);
}
*/
--------------------------------
#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
/*
int main()
{
	char	str1[] = "+47+5";
	char	str2[] = "+548";
	char	str3[] = "123";
	char	str4[] = "3&4567";
	char	str5[] = "3&4567";
	printf("str 47: %d\nstr 548: %d\nstr2 123: %d\nstr : %d\nstr : %d\n",
		atoi(str1),ft_atoi(str2),ft_atoi(str3),ft_atoi(str4),ft_atoi(str5));
}
*/
