/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:47:52 by stissera          #+#    #+#             */
/*   Updated: 2022/03/28 13:40:01 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_o(t_printf *p, unsigned int param)
{
	p->convertion = ft_uitoo((int)param);
	convert_append(p, '0');
	if (p->size > 0)
		convert_size(p);
}
