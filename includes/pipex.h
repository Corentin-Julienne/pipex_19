/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:39:06 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/23 18:31:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/vanilla_libft/libft_vanilla.h"
#include "../libft/gnl_libft/get_next_line.h"
#include "../libft/ft_printf_libft/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

// errors management functions

void	handle_fd_errors(int fd_num);
void	handle_pipe_and_forks_errors(char *error_type);
void	handle_dup2_errors(char *error_type);

// free function (fake for now)

void	fake_func(void);

//  pipex core functions

int		retrieve_path(char	*envp_part);
void	process_child_1(int fd_1, int *pipe_arr, char **argv, char **envp);
void	process_child_2(int fd_2, int *pipe_arr, char **argv, char **envp);
void	pipex(int fd_1, int fd_2, char **argv, char **envp);

#endif