/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:52:03 by alex              #+#    #+#             */
/*   Updated: 2023/05/13 22:06:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_general_free(char** path_matrix)
{
	int	i;

	i = 0;
 	if (!path_matrix)
		return ;
	while (path_matrix[i])
	{
		free(path_matrix[i]);
		i++;
	}
	free(path_matrix);
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