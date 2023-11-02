/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:43:46 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/02 14:38:08 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#indef LIBFT_H
#define LIBFT_H
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *str);

void    *ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char *ft_itoa(int n);
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);

#endif