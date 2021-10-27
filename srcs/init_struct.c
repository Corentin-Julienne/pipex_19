/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:21:47 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/24 14:29:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_vars *vars, char **argv, char **envp)
{
	vars->i = 0;
	vars->j = 0;
	vars->argv = argv;
	vars->envp = envp;
}

void	reset_struct_iters(t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;	
}
