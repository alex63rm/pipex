/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:26 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/28 20:41:56 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

/*
It is a good practice to initialize all the variables inside the struct 
until they are ready to be used. I also need it to save the argv, because they
are only available in the first instance of the program. When the program gets 
replaced by execve, all the previous information that was not saved is lost
*/
static void	ft_init_struct(t_path* main, char** argv)
{
	main->path = NULL;
	main->path_matrix = NULL;
	main->final_matrix = NULL;
	main->cmd_one = argv[2];
	main->cmd_two = argv[3];
	main->cmd_list = NULL;
	printf("finished initializing variables\n");
}

/*
argv[0], argv[1], argv[2], argv[3], argv[4]
./pipex  infile    cmd1     cmd2	outfile
1. First we need to open the infile
2. We need to open or create the outfile
3. Now we have 5 fd open: stdin (0), stdout (1), stderr(2), fd_in(3), fd_out(4)
4. Now, from the envp variable that contains a lot of data, we need several things:
	a. Select just the line starting with PATH (ft_get_path)
	b. This line is composed of several paths separated by :, split it
	c. Remove the first "PATH=" words
	d. Add "/" at the end of all the lines 
that contains the PATH. It still is a long string composed of several paths, so 
we need to do a split and treat them as separate paths
5. The next step is to save the commands that we are receiving in the command line
*/
int	main(int argc, char** argv, char** envp)
{
	//ft_find_path(env);
	t_path	main;
	
	if (argc == 5)
	{
		ft_init_struct(&main, argv);
		// open infile 
		main.fd_in = open(argv[1], O_RDONLY);
		printf("in_fd is |%d|\n", main.fd_in);
		// open/create outfile
		main.fd_out = open(argv[4], O_WRONLY | O_CREAT, 0644);
		printf("out_fd is |%d|\n", main.fd_out);
		if (main.fd_in < 0 || main.fd_out < 0)
			ft_exit_error(1, NULL);
		// find path
		//ft_print_env(envp);
		main.path = ft_get_path(envp);
		//printf("%s\n", main.path);
		main.path_matrix = ft_split(main.path, ':');
		//ft_print_env(main.path_matrix);
		// CREO QUE AQUI TENGO LEAK, EN FT_ADD_CHAR
		main.final_matrix = ft_add_char(&main);
		printf("---------------final matrix-------------\n");
		ft_print_env(main.final_matrix);
		printf("---------------final matrix-------------\n");
		ft_fork(&main, envp);
		
		// this code is also part of the child
		printf("MAIN final print\n");
		// FREE THE SPLIT (CHAR** path_matrix)
		ft_general_free(&main);
		// close all the fds??
	}
	else
	{
		perror("Error. Argc != 5");
		exit (1);
	}
	return (0);
}