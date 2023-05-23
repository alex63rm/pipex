/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:35 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/23 22:54:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This function will be called before the main returns or before any exit
function, to ensure all the dynamically allocated memory has been freed
before the program ends
*/
void	ft_general_free(t_path* main)
{
	int	i;

	i = 0;
	if (main->path_matrix != NULL)
	{
		while (main->path_matrix[i])
		{
			free(main->path_matrix[i]);
			i++;
		}
		free(main->path_matrix);
	}
	//  SI PONGO ESTO TENGO SIGSEV
/* 	i = 0;
	if (!main->final_matrix)
		return ;
	while (main->final_matrix[i])
	{
		free(main->final_matrix[i]);
		i++;
	}
	free(main->final_matrix);
	 */
	i = 0;
	if (main->cmd_list != NULL)
	{
		while (main->cmd_list[i])
		{
			free(main->cmd_list[i]);
			i++;
		}
		free(main->cmd_list);
	}
}

/*
This function will print a specific message depending on the 
error message received as argument
*/
void	ft_exit_error(int err_code, t_path* main)
{
	// REMOVE PRINTF!!!!!
	if (err_code == 1)
		printf("Error. Input or output file error\n");
/* 	if (err_code == 2)
		printf("Error. Unable to create output file\n"); */
	if (err_code == 3)
		printf("Error. Argc != 5\n");
	if (err_code == 4)
		printf("Error. Path not found\n");
	if (err_code == 5)
		printf("Error. Unable to create pid fork\n");
	if (err_code == 6)
		printf("Error. Unable to run execve()\n");
	if (err_code == 7)
		printf("Error. Unable to save argument list\n");
	if (err_code == 8)
		printf("Error. Command not found");
	
	ft_general_free(main);
	
	exit(1);
}