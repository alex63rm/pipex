/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:49:57 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/16 21:36:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//--------------------------------STRUCT-------------------------------------

typedef	struct s_path
{
	char*	path;
	char**	path_matrix;  // this is the matrix without the last /
	char**	final_matrix; // (this is the matrix with the last /)
	int		pid;
	int		fd[2];
	
} t_path;


//---------------------------------LIBFT--------------------------------------

char**	ft_split(char const *s, char c);
char*	ft_strchr(const char *s, int c);
char*	ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);



//----------------------------------MAIN-------------------------------------

void	ft_init_struct(t_path* main);
void	ft_exit_error(int err_code);
char*	ft_get_path(char** env);
void	ft_print_env(char** env);	// DELETE
void	ft_general_free(t_path* main);
char**	ft_add_char(char** path_matrix, char** final_matrix);
void	ft_fork(t_path* main);


#endif