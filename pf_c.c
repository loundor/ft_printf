/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:50:50 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 12:12:47 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_c(t_printf *p, char param)
{
	if (param == 0)
	{		
		p->convertion = (char *)malloc(sizeof(char) * 1);
		if (!p->convertion)
			return ;
		p->convertion[0] = '\0';
		p->len++;
	}
	else
	{
		p->convertion = (char *)malloc(sizeof(char) * 2);
		if (!p->convertion)
			return ;
		p->convertion[1] = '\0';
		p->convertion[0] = param;
	}
	if (p->size > 0)
	{
		if (param == 0)
			p->size--;
		convert_size(p);
	}
}
