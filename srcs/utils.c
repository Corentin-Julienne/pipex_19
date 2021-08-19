/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:52:51 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/19 15:52:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void	ft_strdel(char	**str) // a implementer dans libft
{
	if (*str)
	{
		free(str);
		*str = NULL;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*copy;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	copy = malloc((strlen(s1) + strlen(s2) + 1) * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

