/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:49 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/21 20:12:32 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This functions filters from the envp text just the line that contains the
first characters of PATH= where the executables are. We find the line, 
remove the PATH=, add the / at the end and return it
*/
char	*ft_get_path(char **envp)
{
	int		i;
	int		j;
	char	*temp_path;
	char	*final_path;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' \
			&& envp[i][3] == 'H')
			{
				temp_path = envp[i];
				final_path = ft_strchr(temp_path, '/');
				return (final_path);
			}
			j++;
		}
		i++;
	}
	ft_exit_error(2, NULL);
	return (NULL);
}
