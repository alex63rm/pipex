/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:57:17 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/28 21:13:40 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*(needle + i) == '\0')
		return ((char *)haystack);
	while (*(haystack + i) != '\0' && i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && i + j < len)
		{
			if (*(needle + j + 1) == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}
