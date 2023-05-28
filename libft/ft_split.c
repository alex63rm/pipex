/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:06:25 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/28 20:20:39 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
			continue ;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	i;
	unsigned int	word_start;
	unsigned int	word_nb;

	new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new)
		return (0);
	i = 0;
	word_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			new[word_nb] = ft_substr(s, word_start, i - word_start);
			word_nb++;
			continue ;
		}
		i++;
	}
	new[word_nb] = 0;
	return (new);
}
