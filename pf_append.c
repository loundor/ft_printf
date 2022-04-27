/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:21:57 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 17:06:23 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	convert_append(t_printf *p, char set)
{
	int		size;
	char	*ret;

	size = ft_strlen(p->convertion);
	ret = (char *)malloc(sizeof(char) * size + 2);
	if (!ret)
		return ;
	ret[size + 1] = '\0';
	ret[0] = set;
	while (size-- > 0)
		ret[size + 1] = p->convertion[size];
	free(p->convertion);
	p->convertion = ret;
	ret = NULL;
}

void	writing_until_mod(t_printf *p)
{
	while (p->str[p->index] != '%' && p->str[p->index] != '\0')
	{
		ft_putchar_fd(p->str[p->index], 1);
		p->index++;
		p->len++;
	}
}
