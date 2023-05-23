/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:49 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/23 22:24:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
It is a good practice to initialize all the variables inside the struct 
until they are ready to be used
*/
void	ft_init_struct(t_path* main)
{
	main->path = NULL;
	main->path_matrix = NULL;
	main->final_matrix = NULL;
	main->cmd_list = NULL;
	printf("finished initializing variables\n");
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
				return (final_path);
			}
			j++;
		}
		i++;
	}
	ft_exit_error(4, NULL);
	return (NULL);
}

/*
This function takes the path matrix and will add the final '/' so that
all the directories can be used later on to find the commands
*/
char**	ft_add_char(t_path* main)
{
	int 	i;
	//char**	final_matrix;

	//final_matrix = NULL;
	// ¿POR QUE NECESITO ESTA IGUALDAD????
	//main->final_matrix = (char**)malloc(sizeof(char *) * 100);
	// AQUI TENGO MEMORY LEAKS
	main->final_matrix = main->path_matrix;
	i = 0;
	while (main->path_matrix[i])
	{
		main->final_matrix[i] = ft_strjoin(main->path_matrix[i], "/");
		//printf("paths are %s\n", main->final_matrix[i]);
		i++;
	}
	//ft_general_free(main);
	return (main->final_matrix);
}
