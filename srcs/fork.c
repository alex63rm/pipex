/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:13:30 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/22 21:39:51 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

This function first splits the first command that we received and saves it
in a 2D array (or list of arrays)
*/
static void	ft_child(t_path* main, char** envp)
{
	printf("entered ft_child\n");
	// read from the infile
	dup2(main->fd_in, STDIN_FILENO);
	// write to fd[1], the pipe
	dup2(main->fd[1], STDOUT_FILENO);
	// close what is not needed
	close(main->fd[1]);
	close(main->fd[0]);
	close(main->fd_in);
	close(main->fd_out);
	printf("this should be sent to the pipe");
	ft_join_command(main->final_matrix, main->cmd_one);
	
	
	// SEGUIR AQUI CON LA EJECUCION
	(void)envp;
/* 	main->cmd_list = ft_split(main->cmd_one, ' ');
	if(!main->cmd_list)
		ft_exit_error(7, main);
	ft_print_env(main->cmd_list);
	while(main->final_matrix[i])
	{
		
	}
	(void)
	execve(main->f) */
/* 	if (execve() == -1)
		ft_exit_error(6, &main); */
}

/*
This function creates the fork. When we call the fork:
It returns 0 to the child
It returns the pid of the child to the parent
It returns -1 if there was an error
Very important, make the parent wait for the child to finish
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
			printf("parent pid is: |%d|\n", getpid());

		}
}