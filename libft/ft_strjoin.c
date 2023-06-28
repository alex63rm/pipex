/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:10:41 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/28 21:14:49 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	*ptr;

	n = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * n + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(ptr + i + j) = *(s2 + j);
		j++;
	}
	*(ptr + i + j) = '\0';
	return (ptr);
}
