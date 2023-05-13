/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:18:46 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/13 16:36:21 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
argv[0], argv[1], argv[2], argv[3], argv[4]
./pipex  infile    cmd1     cmd2	outfile
1. First we need to open the infile
2. We need to open the outfile
3. Now we have 5 fd open: stdin (0), stdout (1), stderr(2), fd_in(3), fd_out(4)

*/
int	main(int argc, char** argv, char** envp)
{
	ft_print_env(envp);

	char* path;
	
	if (argc == 5)
	{
		// open infile
		if (open(argv[1], O_RDONLY) < 0)
			ft_exit_error(1);
		// open outfile
		if (open(argv[4], O_WRONLY | O_CREAT, 0644) < 0)
			ft_exit_error(2);
		// find path
		path = ft_get_path(envp);
		printf("%s\n", path);
		//ft_find_path(env);
		// creates pipe and fork
		// execute command and redirect output
		//
		

		
	}
	else
		// ft_exit_error
		ft_exit_error(3);
	return (0);
}