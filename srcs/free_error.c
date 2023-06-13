/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:35 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/13 20:22:04 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This function will be called before the main returns or before any exit
function, to ensure all the dynamically allocated memory has been freed
before the program ends
*/
void	ft_general_free(t_path *main)
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
error message received as argument. Perror does not exit the program,
we exit with status code 1 except if the command is not found,
where we exit with exit code 127: command not found
*/
void	ft_exit_error(int err_code, t_path *main)
{
	if (err_code == 1)
		ft_putstr_fd("Error. fd error\n", 2);
	if (err_code == 2)
		ft_putstr_fd("Error. Path not found in environment\n", 2);
	if (err_code == 3)
		ft_putstr_fd("Error. Unable to create fork\n", 2);
	if (err_code == 4)
		ft_putstr_fd("Error. Command not found\n", 2);
	if (err_code == 5)
		ft_putstr_fd("Error. Unable to create pipe\n", 2);
	ft_general_free(main);
	if (err_code == 4)
		exit(127);
	exit(1);
}
