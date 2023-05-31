/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:13:30 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/31 21:50:12 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This function joins the path and the command name (without the option
flags). It loops over all the paths and checks if the file exists with the 
access function. If the command is not found or cannot be accessed, the 
function returns 1.
*/
static int	ft_join_command(t_path *main)
{
	fprintf(stderr, "entered ft_join_command\n");
	int		i;

	i = 0;
	while (main->final_matrix[i])
	{
		
		main->path_command = ft_strjoin(main->final_matrix[i], main->cmd_list[0]);
		fprintf(stderr, "path is: %s\n", main->path_command);	
		if (access(main->path_command, F_OK) == 0)
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
This function first splits the first command and its options or flags and saves it
in a 2D array (or list of arrays).
Then it checks if the command was found and can be accessed.
Finally it executes the command, which means the whole process is replaced and it
acts as a return.
*/
static void	ft_child(t_path* main, char** envp)
{
	//printf("entered ft_child\n");
	// read from the infile
	dup2(main->fd_in, STDIN_FILENO);
	// write to fd[1], the pipe
	dup2(main->fd[1], STDOUT_FILENO);
	// close what is not needed
	close(main->fd_in);
	close(main->fd[1]);
	// close the rest that are not needed
	close(main->fd[0]);
	close(main->fd_out);
	main->cmd_list = ft_split(main->cmd_one, ' ');
	
	fprintf(stderr, "first command is: ||%s||\n", main->cmd_list[0]);
	if (ft_join_command(main) == 1)
		ft_exit_error(8, main);

	// perror prints to 2, so I can see it in the screen
	fprintf(stderr, "|||||command_found||||||\n");
	write(2, "test\n", 5);
	// SEGUIR AQUI CON LA EJECUCION
	if (execve(main->path_command, main->cmd_list, envp) != 0)
		ft_exit_error(6, main);
}

/*
This function first splits the second command and its options or flags and saves it
in a 2D array (or list of arrays).
Then it checks if the command was found and can be accessed.
Finally it executes the command, which means the whole process is replaced and it
acts as a return.
*/
static void	ft_parent(t_path* main, char** envp)
{
	dup2(main->fd[0], STDIN_FILENO);
	dup2(main->fd_out, STDOUT_FILENO);
	close(main->fd[0]);
	close(main->fd_out);
	close(main->fd[1]);
	close(main->fd_in);
	main->cmd_list = ft_split(main->cmd_two, ' ');
	fprintf(stderr, "argv[3] is: %s\n", main->cmd_list[0]);
	
	fprintf(stderr, "second command is: ||%s||\n", main->cmd_list[0]);
	if (ft_join_command(main) == 1)
		ft_exit_error(8, main);
	
	fprintf(stderr, "|||||command_found||||||\n");
	if (execve(main->path_command, main->cmd_list, envp) != 0)
		ft_exit_error(6, main);
}

/*
This function creates the fork. When we call the fork:
It returns 0 to the child
It returns the pid of the child to the parent
It returns -1 if there was an error
Both processes start running in paralel, so we need to control
the flow: in this case, make the parent wait for the child to finish
*/
void	ft_fork(t_path* main, char** envp)
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
			ft_child(main, envp);
			
			// I can even finish the child process
			//ft_exit_error(3, NULL); 
			return ;
		}
		else
		{
			wait(NULL);
			printf("I am in the parent\n");
			ft_parent(main, envp);
			printf("parent pid is: |%d|\n", getpid());

		}
}