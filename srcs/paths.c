/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:13:58 by cjulienn          #+#    #+#             */
/*   Updated: 2021/10/26 11:20:35 by cjulienn         ###   ########.fr       */
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
