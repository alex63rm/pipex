/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:53:38 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 23:23:25 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(ptr + i) = f(i, *(s + i));
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
