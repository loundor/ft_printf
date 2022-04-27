/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:35:02 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 16:53:42 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_d_i(t_printf *p, int param)
{
	char	*ret;

	p->convertion = ft_itoa((int)param);
	if (p->size != 0 && p->size_ap != 0)
		p->zfill = 0;
	if (p->space_pos == 1 && p->convertion[0] != '-')
		convert_append(p, ' ');
	else if (p->plus_pos && p->convertion[0] != '-')
		convert_append(p, '+');
	ret = convert_d_i_next(p, &param);
	if (p->size > 0)
	{
		convert_size(p);
		pf_check_minus(p->convertion, p->zfill);
	}
	if (p->size_ap > 0)
		pf_check_minus_space(p->convertion, p->dot);
}

char	*convert_d_i_next(t_printf *p, int *param)
{
	char	*ret;

	ret = NULL;
	if (p->dot == 1 && p->size_ap != 0
		&& (p->size + p->size_ap > ft_strlen(p->convertion)))
	{
		if (p->plus_pos || p->left_justify)
			p->size_ap++;
		if ((int)param < 0 && p->plus_pos == 0 && p->left_justify == 0)
			p->size_ap++;
		ret = (char *)malloc(sizeof(char) * p->size_ap + 1);
		if (!ret)
			return (NULL);
		ft_strcfill(ret, '0', p->size_ap);
		ret = ft_memecpy(ret, p->convertion, p->size_ap - 1);
		ret[p->size_ap] = '\0';
		free(p->convertion);
		p->convertion = ret;
		ret = NULL;
	}
	return (ret);
}

void	pf_check_minus(char *p, int s)
{
	int	i;

	i = 1;
	while (p[i])
	{
		if (p[i] == '-' && s == 1)
		{
			p[0] = '-';
			p[i] = '0';
			return ;
		}
		if (p[i] == '+' && s == 1)
		{
			p[0] = '+';
			p[i] = '0';
			return ;
		}
		i++;
	}
	return ;
}

void	pf_check_minus_space(char *p, int s)
{
	int	i;
	int	j;

	j = 0;
	while (p[j] == ' ')
		j++;
	i = j;
	if (p[j] == '0')
	{
		while (p[i])
		{
			if (p[i] == '-' && s == 1)
			{
				p[j] = '-';
				p[i] = '0';
			}
			if (p[i] == '+' && s == 1)
			{
				p[j] = '+';
				p[i] = '0';
			}
			i++;
		}
	}
	return ;
}
