/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:56:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:17:38 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(aux + i) == (unsigned char)c)
			return ((void *)(aux + i));
		i++;
	}
	return (0);
}
