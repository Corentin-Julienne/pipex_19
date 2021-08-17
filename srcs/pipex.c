/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:39:46 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/17 17:18:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	process_child_1(int fd_1, int *pipe_arr, char **argv, char **envp) // manage input
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	char	*tmp;
	int		i;

	// dupping phase
	dup2(fd_1, STDIN_FILENO);
	dup2(pipe_arr[1], STDOUT_FILENO);
	close(pipe_arr[0]);
	close(fd_1);
	// parsing phase
	paths = ft_split(envp, ":");
	cmds = ft_split(argv[2], " ");
	i = 0;
	while (paths++)
	{
		cmd = ft_strjoin(paths[i], argv[2]); // rajouter un "/" ?
		printf("%s\n", cmd); // a enlever
		execve(cmd, cmds, envp);
		free(cmd);
	}
	return (EXIT_FAILURE);	
}

void	process_child_2(int fd_2, int *pipe_arr, char **argv, char **envp) // manage output
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	char	*tmp;
	int		i;
	// dupping phase
	dup2(fd_2, STDOUT_FILENO);
	dup2(pipe_arr[0], STDIN_FILENO);
	close(pipe_arr[1]);
	close(fd_2);
	// parsing phase
	paths = ft_split(envp, ":");
	cmds = ft_split(argv[3], " ");
	i = 0;
	while (paths++)
	{
		cmd = ft_strjoin(paths[i], argv[3]); // rajouter un "/" ?
		printf("%s\n", cmd); // a enlever
		execve(cmd, cmds, envp);
		free(cmd);
	}
	return (EXIT_FAILURE);
}

void	pipex(int fd_1, int fd_2, char **argv, char **envp)
{
	int		pipe_output;
	int		pipe_arr[2];
	pid_t	proc_child_1;
	pid_t	proc_child_2;
	int		status;
	
	pipe_output = pipe(pipe_arr);
	if (pipe_output == -1)
	{
		ft_putstr_fd("Error !\n", 2); // change error message or even function using perror
		exit (0); // change exit argument
	}
	proc_child_1 = fork(); // fork does not take arguments
	if (proc_child_1 < 0)
         return (perror("Forking error : "));
    if (proc_child_1 == 0)
        process_child_1(fd_1, pipe_arr, argv, envp);
	proc_child_2 =  fork();
	if (proc_child_2 < 0)
		return (perror("Forking error : "));
	if (proc_child_2 == 0)
		process_child_2(fd_2, pipe_arr, argv, envp);
	// add close for pipes
	close(pipe_arr[0]);
	close(pipe_arr[1]);
	// add waitpid
	status = 0;
	waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_1;
	int	fd_2;
	
	if (argc != 5) // if wrong number of arguments, retrun an error message and -1
	{
		ft_putstr_fd("Error !\n", 2); // change error message or even function using perror
		return (0);
	}
	fd_1 = open(argv[1], O_RDONLY); // new fd with infile open as read only
	fd_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC); // a voir pour rajouter chmod 
	if (fd_2 == -1 | fd_1 == -1)
	{
		ft_putstr_fd("Error !\n", 2); // change error message or even function using perror
		return (-1);
	}
	void pipex(fd_1, fd_2, argv, envp);
	return (0);
}
