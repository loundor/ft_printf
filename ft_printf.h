/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:33:50 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 17:06:30 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# define FLAGS "-0.# +%"
# define MOD_STD "cspdiuxXo"

typedef struct S_PRINTF
{
	char	*str;
	ssize_t	len;
	size_t	index;

	int		set ;
	int		string;
	int		pointer;
	int		decimal;
	int		udecimal;
	int		hexa;
	int		left_justify;
	int		zfill;
	size_t	size;
	size_t	size_ap;
	int		space_pos;
	int		plus_pos;
	char	hash;
	int		dot;
	int		octal;
	int		mod;
	char	*convertion;
}	t_printf;

int			ft_printf(const char *format, ...);
t_printf	struct_init(const char *param, t_printf *p);
void		writing_until_mod(t_printf *p);
void		check_mod(t_printf *p);
void		check_mod_next(t_printf *p);
void		check_mod_std(t_printf *p);
void		check_mod_nbr(t_printf *p);
void		check_mod_nbr_ap(t_printf *p);
void		convert_mod(t_printf *p, void *param);
void		write_mod(t_printf *p);
t_printf	free_param(t_printf *p);
void		convert_c(t_printf *p, char param);
void		convert_s(t_printf *p, char *param);
void		convert_p(t_printf *p, void *param);
void		convert_d_i(t_printf *p, int param);
char		*convert_d_i_next(t_printf *p, int *param);
void		convert_ud(t_printf *p, unsigned int param);
void		convert_h(t_printf *p, unsigned int param);
void		convert_o(t_printf *p, unsigned int param);
void		convert_left(t_printf *p);
void		convert_zero(t_printf *p);
void		convert_size(t_printf *p);
void		convert_dot(t_printf *p);
void		convert_hash(t_printf *p);
void		convert_append(t_printf *p, char set);
void		pf_check_minus(char *p, int s);
void		pf_check_minus_space(char *p, int s);
void		convert_b16(unsigned long adress, t_printf *p, int i);

#endif
