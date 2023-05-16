/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:11:44 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/16 21:50:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Initialize the struct variables to point to null until they are ready to be
used
*/
void	ft_init_struct(t_path* main)
{
	printf("entered init\n");
	main->path = NULL;
	main->path_matrix = NULL;
	main->final_matrix = NULL;
	
}

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
/*
This functions filters from the envp text just the line that contains the
first characters of PATH= where the executables are. We find the line, 
remove the PATH=, add the / at the end and return it
*/
char* ft_get_path(char** envp)
{
	int		i;
	int		j;
	char*	temp_path;
	char*	final_path;
	
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				printf("found path\n");
				temp_path = envp[i];
				final_path = ft_strchr(temp_path, '/');
				printf("final path is |%s|\n", final_path);
				return (final_path);
			}
			j++;
		}
		i++;
	}
	ft_exit_error(4);
	return (NULL);
}

/*
This function takes the path matrix and will add the final '/' so that
all the directories can be used later on to find the commands
*/
char**	ft_add_char(char** path_matrix, char **final_matrix)
{
	int 	i;
	//char**	final_matrix;

	//final_matrix = NULL;
	// ¿POR QUE NECESITO ESTA IGUALDAD????
	final_matrix = path_matrix;
	i = 0;
	while (path_matrix[i])
	{
		final_matrix[i] = ft_strjoin(path_matrix[i], "/");
		i++;
	}
	return (final_matrix);
}
