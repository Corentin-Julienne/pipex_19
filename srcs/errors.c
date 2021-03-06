/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:34:53 by cjulienn          #+#    #+#             */
/*   Updated: 2021/10/26 11:21:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_fd_errors(int fd_num)
{
	if (fd_num == 1)	
		ft_putstr_fd("Error : infile cannot be openned\n", 1);
	else
		ft_putstr_fd("Error : outfile cannot be openned\n", 1);
	exit(0);
}

void	handle_pipe_and_forks_errors(char *error_type)
{
	ft_printf("there is a %s error\n", error_type);
	exit(0);
}

void	handle_dup2_errors(char *error_type)
{
	ft_printf("there is a %s error\n", error_type); // changer le mnessage d'erreur
	exit(0);
}


