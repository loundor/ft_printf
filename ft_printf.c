/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:23:16 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 17:06:46 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		param;
	t_printf	p;

	if (!format)
		return (-1);
	va_start (param, format);
	p.index = 0;
	p = struct_init(format, &p);
	while (p.str[p.index])
	{
		writing_until_mod(&p);
		if (p.str[p.index] == '%')
		{
			check_mod(&p);
			if (p.mod == 0)
				convert_mod(&p, (void *)va_arg(param, void *));
			else
				convert_c(&p, '%');
			write_mod(&p);
		}
	}
	va_end(param);
	return (p.len);
}

t_printf	struct_init(const char *param, t_printf *p)
{
	p->str = (char *)param;
	*p = free_param(p);
	return (*p);
}

t_printf	free_param(t_printf *p)
{
	if (p->index == 0)
	{
		p->len = 0;
	}
	p->set = 0;
	p->string = 0;
	p->pointer = 0;
	p->decimal = 0;
	p->udecimal = 0;
	p->hexa = 0;
	p->left_justify = 0;
	p->zfill = 0;
	p->size = 0;
	p->size_ap = 0;
	p->space_pos = 0;
	p->plus_pos = 0;
	p->hash = 0;
	p->convertion = 0;
	p->dot = 0;
	p->mod = 0;
	p->octal = 0;
	return (*p);
}

void	convert_mod(t_printf *p, void *param)
{
	if (p->set == 1)
		convert_c(p, (char)param);
	if (p->string == 1)
		convert_s(p, param);
	if (p->pointer == 1)
		convert_p(p, param);
	if (p->decimal == 1)
		convert_d_i(p, *(int *)&param);
	if (p->udecimal == 1)
		convert_ud(p, *(unsigned int *)&param);
	if (p->hexa == 1 || p->hexa == 2)
		convert_h(p, *(unsigned int *)&param);
	if (p->octal == 1)
		convert_o(p, *(unsigned int *)&param);
	if (p->hash != 0)
		convert_hash(p);
	if (p->size > 0)
		convert_size(p);
}

void	write_mod(t_printf *p)
{
	ft_putstr_fd(p->convertion, 1);
	if (p->convertion[0] == '\0' && p->set == 1)
		write(1, "\0", 1);
	p->len += ft_strlen(p->convertion);
	if (p->convertion)
		free(p->convertion);
	free_param(p);
}
