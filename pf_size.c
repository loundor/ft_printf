/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:32:25 by stissera          #+#    #+#             */
/*   Updated: 2022/03/29 10:44:39 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_size(t_printf *p)
{
	char	*ret;

	if (ft_strlen(p->convertion) >= p->size)
		return ;
	ret = (char *)malloc(sizeof(char) * p->size + 1);
	if (!ret)
		return ;
	if (p->zfill == 1 && p->left_justify == 0 && (p->decimal == 1
			|| p->udecimal == 1))
		ft_strcfill(ret, '0', p->size);
	else
		ft_strcfill(ret, ' ', p->size);
	ret[p->size] = '\0';
	if (p->left_justify == 1 && (p->decimal == 1 || p->string == 1
			||p->udecimal == 1 || p->set == 1 || p->pointer == 1))
		ret = ft_memcpy(ret, p->convertion, ft_strlen(p->convertion));
	else
		ret = ft_memecpy(ret, p->convertion, p->size - 1);
	free(p->convertion);
	p->convertion = ret;
	ret = NULL;
}
