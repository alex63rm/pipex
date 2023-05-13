/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:25:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:48:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	unsigned long	n_len;

	n_len = 0;
	if (n == 0)
		n_len++;
	if (n < 0)
	{
		n = n * -1;
		n_len++;
	}
	while (n > 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

static char	*ft_write_number(char *ptr, unsigned long n_len, long n)
{
	if (n == 0)
		*ptr = '0';
	if (n < 0)
	{
		*ptr = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		*(ptr + --n_len) = (n % 10) + '0';
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		n_len;

	n_len = ft_intlen(n);
	ptr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!ptr)
		return (0);
	ptr = ft_write_number(ptr, n_len, n);
	*(ptr + n_len) = '\0';
	return (ptr);
}
