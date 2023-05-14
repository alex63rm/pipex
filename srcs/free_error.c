/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:52:03 by alex              #+#    #+#             */
/*   Updated: 2023/05/14 15:30:56 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_general_free(t_path* main)
{
	int	i;

	i = 0;
 	if (!main->path_matrix)
		return ;
	while (main->path_matrix[i])
	{
		free(main->path_matrix[i]);
		i++;
	}
	free(main->path_matrix);
}

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