/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:39:06 by cjulienn          #+#    #+#             */
/*   Updated: 2021/10/27 11:43:47 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

typedef struct	s_vars
{
	int			i;
	int			j;
	char		**paths;
	char		*path;
	char		**cmds;
	char		*cmd;
	char		**envp;
	char		**argv;
}				t_vars;


/* errors.c */

void	handle_fd_errors(int fd_num);
void	handle_pipe_and_forks_errors(char *error_type);
void	handle_dup2_errors(char *error_type);

// // free function (fake for now)

// void	fake_func(void); // suppress

/* init_struct.c */

void	init_struct(t_vars *vars, char **argv, char **envp);
void	reset_struct_iters(t_vars *vars);

/* paths.c */

int		retrieve_path(char	*envp_part);

/* pipex.c */

void	process_child_1(int fd_1, int *pipe_arr, t_vars *vars);
void	process_child_2(int fd_1, int *pipe_arr, t_vars *vars);
void	pipex(int fd_1, int fd_2, t_vars *vars);
void	parse_paths_and_cmds(t_vars *vars, int arg_num);

#endif