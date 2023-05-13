/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:29:11 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:33:25 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	
	if (!s1)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
