/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:51:17 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/19 17:31:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// temporary header to suppress later

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void	process_child_1(int fd_1, int *pipe_arr, char **argv, char **envp);
void	process_child_2(int fd_2, int *pipe_arr, char **argv, char **envp);
void	pipex(int fd_1, int fd_2, char **argv, char **envp);
char	**ft_split(char const *s, char c);
void	ft_strdel(char	**str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		retrieve_path(char	*envp_part);

#endif
