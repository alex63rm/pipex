/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:13:30 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/26 21:23:18 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This function joins the path and the command name (without the option
labels). It loops over all the paths and checks if the file exists with the 
access function. If the command is not found or cannot be accessed, the 
function returns 1.
*/

static int	ft_join_command(t_path *main)
{
	fprintf(stderr, "entered ft_join_command\n");
	int		i;
	char*	path_command;

	i = 0;
	while (main->final_matrix[i])
	{
		
		main->path_command = ft_strjoin(main->final_matrix[i], main->cmd_list[0]);
		
		// VER XQ NO ME COGE EL PATH, IGUAL QUITAR LA PRIMERA / ???
		fprintf(stderr, "path is: %s\n", main->path_command);	
		if (access(path_command, F_OK) == 0)
		{
			fprintf(stderr, "path is: %s\n", main->path_command);	
			return (0);
		}
		// puede haber leaks?
		free(main->path_command);
		i++;
	}
	// if not found
	return (1);
}


/*
FD workflow:
1. Child will write to the pipe (fd[1]) instead of stdout.
2. Close the fd[1] which has already been cloned
3. Close the read end of the pipe (fd[0]) that is not needed
In this case, we also have an infile instead of just stdin.
1. Child will read from fd = 3 (infile) instead from stdin (0);
2. Close the fd = 3 that has been cloned
3. Close the fd = 4 (outfile) because this process is not going to write there

Next, check the command and the path for execution.

This function first splits the first command and its options or flags and saves it
in a 2D array (or list of arrays).
*/
static void	ft_child(t_path* main, char** envp, char** argv)
{
	int	i;

	i = 0;
	//printf("entered ft_child\n");
	// read from the infile
	dup2(main->fd_in, STDIN_FILENO);
	// write to fd[1], the pipe
	dup2(main->fd[1], STDOUT_FILENO);
	// close what is not needed
	close(main->fd[1]);
	close(main->fd[0]);
	close(main->fd_in);
	close(main->fd_out);
	main->cmd_list = ft_split(argv[2], 32);
	fprintf(stderr, "first command is: ||%s||\n", main->cmd_list[0]);
	if (ft_join_command(main) == 1)
		ft_exit_error(8, main);

	// perror prints to 2, so I can see it in the screen
	fprintf(stderr, "|||||command_found||||||\n");
	write(2, "test\n", 5);
	// SEGUIR AQUI CON LA EJECUCION
	if(!main->cmd_list)
		ft_exit_error(7, main);
	if (execve(main->path_command, main->cmd_list, envp) != 0)
		ft_exit_error(6, main);
}

/*
This function creates the fork. When we call the fork:
It returns 0 to the child
It returns the pid of the child to the parent
It returns -1 if there was an error
Very important, make the parent wait for the child to finish
*/
void	ft_fork(t_path* main, char** envp, char** argv)
{
		pipe(main->fd);
		printf("pipe fd[0] is %d\n", main->fd[0]);
		printf("pipe fd[1] is %d\n", main->fd[1]);
		main->pid = fork();
		if (main->pid == -1)
			ft_exit_error(5, main);
		if (main->pid == 0)
		{
			printf("I am in the child\n");
			printf("child pid is: |%d|\n", getpid());
			ft_child(main, envp, argv);
			
			// I can even finish the child process
			//ft_exit_error(3, NULL); 
			return ;
		}
		else
		{
			wait(NULL);
			printf("I am in the parent\n");
			printf("parent pid is: |%d|\n", getpid());

		}
}