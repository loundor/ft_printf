/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ud.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:54:42 by stissera          #+#    #+#             */
/*   Updated: 2022/03/28 13:36:38 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_ud(t_printf *p, unsigned int param)
{
	p->convertion = ft_utoa((unsigned int)param);
	if (p->size > 0)
		convert_size(p);
}
