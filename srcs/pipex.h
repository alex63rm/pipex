/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:49:57 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/13 22:20:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//---------------------------------LIBFT--------------------------------------

char**	ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);


//----------------------------------MAIN-------------------------------------

void	ft_exit_error(int err_code);
char*	ft_get_path(char **env);
void	ft_print_env(char** env);	// DELETE
void	ft_general_free(char** path_matrix);
char**	ft_add_char(char** path_matrix);


#endif