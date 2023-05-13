/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:55:21 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:20:10 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*auxsrc;
	char	*auxdst;

	auxsrc = (char *)src;
	auxdst = (char *)dst;
	if (!src && !dst)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			auxdst[len] = auxsrc[len];
		}
		return (dst);
	}
	i = 0;
	while (len--)
	{
		*(auxdst + i) = *(auxsrc + i);
		i++;
	}
	return (dst);
}
