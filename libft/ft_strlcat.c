/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:41:45 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:12:47 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dstsize < dst_len)
		dst_len = dstsize;
	i = 0;
	while (src[i] && dst_len + i + 1 < dstsize)
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	if (i != 0)
		*(dst + dst_len + i) = '\0';
	return (dst_len + ft_strlen(src));
}
