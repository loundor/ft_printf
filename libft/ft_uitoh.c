/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:52:38 by stissera          #+#    #+#             */
/*   Updated: 2022/03/26 10:23:06 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_uitoh(unsigned int nbr)
{
	size_t	size;
	size_t	smalloc;
	char	*ret;

	size = nbr;
	smalloc = 0;
	while (size != 0)
	{
		smalloc++;
		size /= 16;
	}
	ret = (char *)malloc(sizeof(char) * smalloc + 1);
	if (!ret)
		return (NULL);
	ret[smalloc] = '\0';
	size = nbr;
	smalloc--;
	while (size > 0)
	{
		ret[smalloc--] = BASE16[size % 16];
		size /= 16;
	}
	return (ret);
}
