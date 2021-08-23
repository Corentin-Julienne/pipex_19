/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:39:46 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/23 18:34:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	retrieve_path(char	*envp_part)
{
	int		score = 0;

	if (envp_part[0] == 'P')
		score++;
	if (envp_part[1] == 'A')
		score++;
	if (envp_part[2] == 'T')
		score++;
	if (envp_part[3] == 'H')
		score++;
	if (score == 4)
		return (1);
	else
		return (0);
}

void	process_child_1(int fd_1, int *pipe_arr, char **argv, char **envp)
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	char	*path;
	int		i;

	close(pipe_arr[0]);
	if (dup2(fd_1, STDIN_FILENO) == -1)
		handle_dup2_errors("dup2 failed with fd_1\n");
	if (dup2(pipe_arr[1], STDOUT_FILENO) == -1)
		handle_dup2_errors("dup2 failed with pipe[1]\n");
	close(fd_1);
	i = 0;
	while (envp[i] && retrieve_path(envp[i]) == 0)
	{
		if(retrieve_path(envp[i]) == 1)
			path = envp[i] + (5 * sizeof(char));
		i++;
	}
	paths = ft_split(path, ':');	
	cmds = ft_split(argv[2], ' ');
	i = 0;
	while (paths++)
	{
		cmd = ft_strjoin(paths[i], argv[2]); // rajouter un "/" ?
		execve(cmd, cmds, envp);
		free(cmd);
	}
	exit(0);	
}

void	process_child_2(int fd_2, int *pipe_arr, char **argv, char **envp)
{
	char	**paths;
	char	*path;
	char	**cmds;
	char	*cmd;
	int		i;

	close(pipe_arr[1]);
	dup2(fd_2, STDOUT_FILENO);
	dup2(pipe_arr[0], STDIN_FILENO);
	close(fd_2);
	i = 0;
	while (envp[i] && retrieve_path(envp[i]) == 0)
	{
		if(retrieve_path(envp[i]) == 1)
			path = envp[i] + (5 * sizeof(char));
		i++;
	}
	paths = ft_split(path, ':');
	cmds = ft_split(argv[3], ' ');
	i = 0;
	while (paths++)
	{
		cmd = ft_strjoin(paths[i], argv[3]); // rajouter un "/" ?
		execve(cmd, cmds, envp);
		free(cmd);
	}
	printf("error : invalid stuff in child process 2\n");
	exit(0);
}

void	pipex(int fd_1, int fd_2, char **argv, char **envp)
{
	int		pipe_output;
	int		pipe_arr[2];
	pid_t	proc_child_1;
	pid_t	proc_child_2;
	
	pipe_output = pipe(pipe_arr);
	if (pipe_output == -1)
		handle_pipe_and_forks_errors("pipe");
	proc_child_1 = fork();
	if (proc_child_1 < 0)
        handle_pipe_and_forks_errors("fork");
    if (proc_child_1 == 0)
        process_child_1(fd_1, pipe_arr, argv, envp);
	proc_child_2 =  fork();
	if (proc_child_2 < 0)
		handle_pipe_and_forks_errors("fork");
	if (proc_child_2 == 0)
		process_child_2(fd_2, pipe_arr, argv, envp);
	wait(0);
    wait(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_1;
	int		fd_2;
	
	if (argc != 5)
	{
		ft_putstr_fd("Error ! : wrong number of arguments\n", 2);
		return (-1);
	}
	if ((fd_1 = open(argv[1], O_RDONLY)) == -1)
		handle_fd_errors(1);
	if ((fd_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC)) == -1)
		handle_fd_errors(2);
	pipex(fd_1, fd_2, argv, envp);
	(void)envp;
	return (0);
}
