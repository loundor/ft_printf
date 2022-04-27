/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:31:48 by stissera          #+#    #+#             */
/*   Updated: 2022/04/09 12:16:14 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_uitoo(unsigned int nbr)
{
	size_t	size;
	size_t	smalloc;
	char	*ret;

	size = nbr;
	smalloc = 0;
	while (size != 0)
	{
		smalloc++;
		size /= 8;
	}
	ret = (char *)malloc(sizeof(char) * smalloc + 1);
	if (!ret)
		return (NULL);
	ret[smalloc] = '\0';
	size = nbr;
	smalloc--;
	while (size > 0)
	{
		ret[smalloc--] = BASE8[size % 8];
		size /= 8;
	}
	return (ret);
}
