/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:29:37 by stissera          #+#    #+#             */
/*   Updated: 2022/03/22 23:23:35 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_strcfill(void *s, char c, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = c;
		str++;
		n--;
	}
	return ;
}
