/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:13:30 by alejarod          #+#    #+#             */
/*   Updated: 2023/06/14 19:58:01 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
This function joins the path and the command name (without the option
flags).
First, we need to add a slash to the command name, because the path splitted
does not include a slash at the end
It loops over all the paths and checks if the command name is found
and can be accessed with the access function. If the command is not found 
or cannot be accessed, the function returns 1.
*/
static int	ft_join_command(t_path *main)
{
	int		i;
	char	*cmd_list_slash;

	cmd_list_slash = ft_strjoin("/", main->cmd_list[0]);
	i = 0;
	while (main->path_matrix[i])
	{
		main->path_command = ft_strjoin(main->path_matrix[i], cmd_list_slash);
		// REVISAR F_OK
		if (access(main->path_command, F_OK | 1) == 0)
		{
			free(cmd_list_slash);
			return (0);
		}
		free(main->path_command);
		i++;
	}
	free(cmd_list_slash);
	return (1);
}

/*
This function first splits the first command and its options or flags and saves
it in a 2D array (or list of arrays). Then it checks if the command was found 
and can be accessed. Finally it executes the command, which means the whole 
process is replaced and it acts as a return.
*/
static void	ft_child(t_path *main, char **envp)
{
	dup2(main->fd_in, STDIN_FILENO);
	dup2(main->fd[1], STDOUT_FILENO);
	close(main->fd_in);
	close(main->fd[1]);
	close(main->fd[0]);
	close(main->fd_out);
	main->cmd_list = ft_split(main->cmd_one, ' ');
	if (ft_join_command(main) == 1)
		ft_exit_error(4, main);
	execve(main->path_command, main->cmd_list, envp);
}

/*
This function first splits the second command and its options or flags and saves
it in a 2D array (or list of arrays).
Then it checks if the command was found and can be accessed.
Finally it executes the command, which means the whole process is replaced and it
acts as a return.
*/
static void	ft_parent(t_path *main, char **envp)
{
	dup2(main->fd[0], STDIN_FILENO);
	dup2(main->fd_out, STDOUT_FILENO);
	close(main->fd[0]);
	close(main->fd_out);
	close(main->fd[1]);
	close(main->fd_in);
	main->cmd_list = ft_split(main->cmd_two, ' ');
	if (ft_join_command(main) == 1)
		ft_exit_error(4, main);
	execve(main->path_command, main->cmd_list, envp);
}

/*
Before creating the fork, we need to create the pipe to create the fds
where the parent and child process will share information
This function creates the fork. When we call the fork:
It returns 0 to the child
It returns the pid of the child to the parent
It returns -1 if there was an error
Both processes start running in paralel, so we need to control
the flow: in this case, make the parent wait for the child to finish
*/
void	ft_process(t_path *main, char **envp)
{
	int	status;
	
	if (pipe(main->fd) == -1)
		ft_exit_error(5, main);
	main->pid = fork();
	if (main->pid == -1)
		ft_exit_error(3, main);
	if (main->pid == 0)
	{
		ft_putstr_fd("I am in the child\n", 2);
		ft_child(main, envp);
	}
	else
	{
		waitpid(main->pid, &status, 0);
		ft_putstr_fd("I am in the parent\n", 2);
		ft_parent(main, envp);
	}
}
