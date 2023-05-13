/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:19:54 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:10:19 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*auxdst;
	const char	*auxsrc;

	auxdst = dst;
	auxsrc = src;
	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		*(auxdst + i) = *(auxsrc + i);
		i++;
	}
	return (dst);
}
