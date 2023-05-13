/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:11:44 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/13 16:30:09 by alejarod         ###   ########.fr       */
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
		printf("env paths are: %s\n", env[i]);
		i++;
	}
}

char* ft_get_path(char** envp)
{
	int	i, j;
	
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				printf("found path\n");
				return (envp[i]);
			}
			j++;
		}
		i++;
	}
	ft_exit_error(4);
	return("test");
	
}
/*
void	ft_general_free()
{
	
}
*/

void	ft_exit_error(int err_code)
{
	if (err_code == 1)
		printf("Error. Input file not found\n");
	if (err_code == 2)
		printf("Error. Unable to create output file\n");
	if (err_code == 3)
		printf("Error. Argc < 5\n");
	if (err_code == 4)
		printf("Error. Path not found\n");
	
	
	// ft general_free
	
	exit(1);
}