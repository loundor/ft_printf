/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:27:39 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 16:59:16 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	check_mod(t_printf *p)
{
	p->index += 1;
	while (ft_strchr(FLAGS, p->str[p->index]) || ft_isnum(p->str[p->index]))
	{
		check_mod_next(p);
		if (ft_strchr(" ", p->str[p->index]))
			p->space_pos = 1;
		if (ft_strchr("+", p->str[p->index]))
			p->plus_pos = 1;
		if (ft_strchr("%", p->str[p->index]))
		{
			p->mod = 1;
			p->set = 1;
			p->index++;
			return ;
		}
		if (ft_isnum(p->str[p->index])
			&& p->str[p->index] != '0' && p->dot == 0)
			check_mod_nbr(p);
			p->index++;
	}
	check_mod_std (p);
}

void	check_mod_next(t_printf *p)
{
	if (ft_strchr("#", p->str[p->index]))
		p->hash = 1;
	if (ft_strchr("-", p->str[p->index]))
		p->left_justify = 1;
	if (ft_strchr("0", p->str[p->index]))
		p->zfill = 1;
	if (ft_strchr(".", p->str[p->index]))
	{
		p->dot = 1;
		p->index++;
		check_mod_nbr_ap(p);
	}
}

void	check_mod_nbr(t_printf *p)
{
	while (ft_isnum(p->str[p->index]))
	{
		p->size = p->size * 10 + (p->str[p->index] - 48);
		p->index++;
	}
	p->index--;
}

void	check_mod_nbr_ap(t_printf *p)
{
	while (ft_isnum(p->str[p->index]))
	{
		p->size_ap = p->size_ap * 10 + (p->str[p->index] - 48);
		p->index++;
	}
	p->index--;
}

void	check_mod_std(t_printf *p)
{
	if (ft_strchr(MOD_STD, p->str[p->index]))
	{
		if (ft_strchr("o", p->str[p->index]))
			p->octal = 1;
		if (ft_strchr("c", p->str[p->index]))
			p->set = 1;
		if (ft_strchr("s", p->str[p->index]))
			p->string = 1;
		else if (ft_strchr("p", p->str[p->index]))
			p->pointer = 1;
		else if (ft_strchr("d", p->str[p->index])
			|| ft_strchr("i", p->str[p->index]))
			p->decimal = 1;
		else if (ft_strchr("u", p->str[p->index]))
			p->udecimal = 1;
		else if (ft_strchr("x", p->str[p->index]))
			p->hexa = 1;
		else if (ft_strchr("X", p->str[p->index]))
			p->hexa = 2;
		p->index++;
	}
}
