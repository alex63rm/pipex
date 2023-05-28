/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:12:43 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/28 20:42:01 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

//--------------------------------STRUCT-------------------------------------

typedef	struct	s_path
{
	int		fd_in;
	int		fd_out;
	char*	path;
	char**	path_matrix;  // this is the matrix without the last /
	char**	final_matrix; // (this is the matrix with the last /)
	int		pid;
	int		fd[2];
	char*	cmd_one;
	char*	cmd_two;
	char**	cmd_list;
	char*	path_command;
	
} t_path;


//---------------------------------LIBFT--------------------------------------

char**	ft_split(char const *s, char c);
char*	ft_strchr(const char *s, int c);
char*	ft_strjoin(char const *s1, char const *s2);

//----------------------------------MAIN-------------------------------------

void	ft_exit_error(int err_code, t_path* main);
char*	ft_get_path(char** env);
void	ft_print_env(char** env);	// DELETE
void	ft_general_free(t_path* main);
char**	ft_add_char(t_path* main);
void	ft_fork(t_path* main, char** envp);



#endif