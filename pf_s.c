/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:33:37 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 12:14:08 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_s(t_printf *p, char *param)
{
	size_t	size;

	if ((char *)param == NULL)
	{
		p->convertion = (char *)malloc(sizeof(char) * 7);
		if (!p->convertion)
			return ;
		p->convertion[6] = '\0';
		p->convertion = ft_memcpy(p->convertion, "(null)", 6);
	}
	else
	{
		size = ft_strlen((char *)param);
		p->convertion = (char *)malloc(sizeof(char) * size + 1);
		if (!p->convertion)
			return ;
		p->convertion[size] = '\0';
		p->convertion = ft_memcpy(p->convertion, param, size);
	}
	if (p->size > 0)
		convert_size(p);
}
