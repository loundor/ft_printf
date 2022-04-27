/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memecpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:29:15 by stissera          #+#    #+#             */
/*   Updated: 2022/03/23 23:00:45 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memecpy(void *dest, void const *src, size_t n)
{
	unsigned long int	count;
	unsigned char		*dest_cast;
	unsigned char		*src_cast;

	if (!dest && src == NULL)
		return (NULL);
	count = ft_strlen(src);
	dest_cast = (unsigned char *) dest;
	src_cast = (unsigned char *) src;
	while (count != 0)
	{
		dest_cast[n] = src_cast[count - 1];
		n--;
		count--;
	}
	return (dest);
}
