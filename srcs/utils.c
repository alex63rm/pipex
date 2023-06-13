/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:49 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/13 20:49:16 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// temporary function
void ft_print_env(char** env)
{
	int i;

	i = 0;
	while (env[i])
	{
		// QUITAR
		printf("env paths are: %s\n", env[i]);
		i++;
	}
}
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
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
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
