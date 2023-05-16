/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:52:03 by alex              #+#    #+#             */
/*   Updated: 2023/05/17 00:12:23 by alex             ###   ########.fr       */
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
	if (main->path_matrix == NULL)
		return ;
	while (main->path_matrix[i])
	{
		free(main->path_matrix[i]);
		i++;
	}
	free(main->path_matrix);
	main->path_matrix = NULL;
	
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
	main->final_matrix = NULL;
	 */
}

/*
This function will print a specific message depending on the 
error message received as argument
*/
void	ft_exit_error(int err_code)
{
	// REMOVE PRINTF!!!!!
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