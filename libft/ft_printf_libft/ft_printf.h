/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:46:45 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/09 18:44:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../vanilla_libft/libft_vanilla.h"

typedef struct s_parse
{
	va_list		args;
	const char	*format;
	int			rtn;
	int			i;
}				t_parse;

int			ft_printf(const char *format, ...);
void		ft_printer(t_parse *parse_tab);
t_parse		*ft_inialize_data(t_parse *parse_tab, const char *format);
t_parse		*ft_create_parse_tab(const char *format);
void		ft_find_format(t_parse *parse_tab, int index);
void		ft_handle_percent(t_parse *parse_tab);
void		ft_handle_char(t_parse *parse_tab);
void		ft_handle_void_pointer(t_parse *parse_tab);
void		ft_handle_signed_int(t_parse *parse_tab);
void		ft_handle_string(t_parse *parse_tab);
void		ft_handle_unsigned_int(t_parse *parse_tab);
void		ft_handle_hxd_num(t_parse *parse_tab);
void		ft_handle_upper_hxd_num(t_parse *parse_tab);

#endif
