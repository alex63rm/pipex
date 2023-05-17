/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:39:28 by alex              #+#    #+#             */
/*   Updated: 2023/05/18 00:37:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	ft_fork(t_path* main)
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