/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:05:19 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 11:48:35 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_h(t_printf *p, unsigned int param)
{
	int	i;

	if ((unsigned int)param == 0)
	{		
		p->convertion = (char *)malloc(sizeof(char) * 2);
		if (!p->convertion)
			return ;
		p->convertion[0] = '0';
		p->convertion[1] = '\0';
	}
	else
	{
		p->convertion = ft_uitoh((unsigned int)param);
		if (p->hexa == 2 && p->convertion)
		{
			i = 0;
			while (p->convertion[i])
			{
				p->convertion[i] = ft_toupper(p->convertion[i]);
				i++;
			}
		}
	}
	if (p->size > 0)
		convert_size(p);
}
