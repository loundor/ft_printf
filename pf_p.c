/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:34:13 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 12:26:44 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_p(t_printf *p, void *param)
{
	unsigned long	adress;
	int				i;

	i = 1;
	adress = (unsigned long)param;
	while (adress >= 16)
	{
		adress /= 16;
		i++;
	}
	p->convertion = (char *)malloc(sizeof(char) * i + 3);
	if (!p->convertion)
		return ;
	p->convertion[0] = '0';
	p->convertion[1] = 'x';
	adress = (unsigned long)param;
	if (adress == 0)
		p->convertion[2] = '0';
	convert_b16(adress, p, i);
	p->convertion[i + 2] = '\0';
	if (p->size > 0)
		convert_size(p);
}

void	convert_b16(unsigned long adress, t_printf *p, int i)
{
	int				j;

	j = 0;
	while (adress > 0)
	{
		p->convertion[i + 1 - j] = BASE16[adress % 16];
		adress /= 16;
		j++;
	}
}
