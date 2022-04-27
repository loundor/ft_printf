/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:40:42 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 12:14:33 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_hash(t_printf *p)
{
	if (p->hexa == 1 && p->convertion[0] != '0')
	{
		convert_append(p, 'x');
		convert_append(p, '0');
	}
	if (p->hexa == 2 && p->convertion[0] != '0')
	{
		convert_append(p, 'X');
		convert_append(p, '0');
	}
}
