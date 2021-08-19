/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:34:47 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/19 17:30:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "utils.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

int main(int argc, char **argv, char **envp)
{
	int		i = 0;
	char	*path;
	(void)argc;
	(void)argv;
	path = NULL;
	while(envp[i])
	{
		if (retrieve_path(envp[i]) == 1)
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	printf("%s\n\n", path);
	path = path + (5 *sizeof(char));
	printf("%s\n\n", path);
	
	return (0);
}