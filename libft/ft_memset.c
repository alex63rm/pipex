/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:19:58 by alejarod          #+#    #+#             */
/*   Updated: 2022/09/28 21:10:50 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*aux;

	aux = b;
	i = 0;
	while (i < len)
	{
		*(aux + i) = (unsigned char) c;
		i++;
	}
	return ((void *)aux);
}
