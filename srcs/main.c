/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:18:46 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/15 19:59:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
argv[0], argv[1], argv[2], argv[3], argv[4]
./pipex  infile    cmd1     cmd2	outfile
1. First we need to open the infile
2. We need to open the outfile
3. Now we have 5 fd open: stdin (0), stdout (1), stderr(2), fd_in(3), fd_out(4)
4. Now, from the envp variable that contains a lot of data, we need several things:
	a. Select just the line starting with PATH (ft_get_path)
	b. This line is composed of several paths separated by :, split it
	c. Remove the first "PATH=" words
	d. Add "/" at the end of all the lines 
that contains the PATH. It still is a long string composed of several paths, so 
we need to do a split and treat them as separate paths
*/
int	main(int argc, char** argv, char** envp)
{
	//ft_find_path(env);
	t_path	main;
	
	ft_init_struct(&main);
	if (argc == 5)
	{
		// open infile 
		if (open(argv[1], O_RDONLY) < 0)
			ft_exit_error(1);
		// open outfile
		if (open(argv[4], O_WRONLY | O_CREAT, 0644) < 0)
			ft_exit_error(2);
		// find path
		//ft_print_env(envp);
		main.path = ft_get_path(envp);
		//printf("%s\n", path);
		main.path_matrix = ft_split(main.path, ':');
		ft_print_env(main.path_matrix);
		//main.final_matrix = ft_add_char(main.path_matrix);
		//ft_print_env(main.final_matrix);
		// I NEED TO ADD THE FINAL /
		pipe(main.fd);
		printf("pipe fd[0] is %d\n", main.fd[0]);
		printf("pipe fd[1] is %d\n", main.fd[1]);
		//main.pid = fork();
		printf("parent pid is: |%d|\n", getpid());
		printf("parent or parent pid is: |%d|\n", getppid());
		

		// creates pipe and fork
		// execute command and redirect output
		//
		

		
	}
	else
		// ft_exit_error
		ft_exit_error(3);
	
	// FREE THE SPLIT (CHAR** path matrix)
	//ft_general_free(&main);
	// APUNTAR !!!!
	// system("leaks pipex");
	return (0);
}