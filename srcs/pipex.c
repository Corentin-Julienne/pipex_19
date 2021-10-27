/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:39:46 by cjulienn          #+#    #+#             */
/*   Updated: 2021/10/26 15:53:27 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parse_paths_and_cmds(t_vars *vars, int arg_num)
{
	vars->i = 0;
	if (retrieve_path(vars->envp[vars->i]) == 1)
		vars->path = vars->envp[vars->i] + (5 * sizeof(char));
	vars->i++;
	while (vars->envp[vars->i] && retrieve_path(vars->envp[vars->i]) == 0)
	{
		if (retrieve_path(vars->envp[vars->i]) == 1)
			vars->path = vars->envp[vars->i] + (5 * sizeof(char));
		vars->i++;
	}
	vars->paths = ft_split(vars->path, ':');
	vars->cmds = ft_split(vars->argv[arg_num], ' ');
	vars->i = 0;
}
	
void	process_child_1(int fd_1, int *pipe_arr, t_vars *vars)
{
	char	*full_path;
	
	close(pipe_arr[0]);
	if (dup2(fd_1, STDIN_FILENO) == -1)
		handle_dup2_errors("dup2 failed with fd_1\n");
	if (dup2(pipe_arr[1], STDOUT_FILENO) == -1)
		handle_dup2_errors("dup2 failed with pipe[1]\n");
	close(fd_1);
	parse_paths_and_cmds(vars, 2);
	while (vars->paths++)
	{
		full_path = ft_strjoin(vars->path[vars->i], "/");
		if (!full_path)
			exit(0);
		vars->cmd = ft_strjoin(full_path, vars->argv[2]);
		if (!vars->cmd)
			exit(0);
		execve(vars->cmd, vars->cmds, vars->envp);
		free(vars->cmd);
		free(full_path);
	}
	printf("error : invalid stuff in child process 1\n");
	exit(0);
}

void	process_child_2(int fd_2, int *pipe_arr, t_vars *vars)
{
	char	*full_path;
	
	close(pipe_arr[1]);
	dup2(fd_2, STDOUT_FILENO);
	dup2(pipe_arr[0], STDIN_FILENO);
	close(fd_2);
	parse_paths_and_cmds(vars, 3);
	while (vars->paths++)
	{
		full_path = ft_strjoin(vars->path[vars->i], "/");
		if (!full_path)
			exit(0);
		vars->cmd = ft_strjoin(full_path, vars->argv[3]);
		if (!vars->cmd)
			exit(0);
		execve(vars->cmd, vars->cmds, vars->envp);
		free(vars->cmd);
		free(full_path);
	}
	printf("error : invalid stuff in child process 2\n");
	exit(0);
}

void	pipex(int fd_1, int fd_2, t_vars *vars)
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
		process_child_1(fd_1, pipe_arr, vars);
	proc_child_2 = fork();
	if (proc_child_2 < 0)
		handle_pipe_and_forks_errors("fork");
	if (proc_child_2 == 0)
		process_child_2(fd_2, pipe_arr, vars);
	wait(0); // waitpid ?
	wait(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_1;
	int		fd_2;
	t_vars	*vars;

	if (argc != 5)
	{
		ft_putstr_fd("Error ! : wrong number of arguments\n", 1);
		return (-1);
	}
	fd_1 = open(argv[1], O_RDONLY);
	if (fd_1 == -1)
		handle_fd_errors(1);
	fd_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_2 == -1)
		handle_fd_errors(2);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (-1);
	init_struct(vars, argv, envp);
	pipex(fd_1, fd_2, vars);
	free(vars);
	(void)envp;
	return (0);
}
