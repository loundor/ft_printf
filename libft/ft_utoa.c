/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:09:59 by stissera          #+#    #+#             */
/*   Updated: 2022/03/23 21:58:40 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*ft_utoawrite(unsigned int n, unsigned int size)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char) * size + 1);
	if (!ret)
		return (0);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	return (ret);
}

static char	*ft_utoazero(void)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char) * 2);
	ret[0] = (char) 48;
	ret[1] = 0;
	return (ret);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	size;
	unsigned int	ssize;
	unsigned int	len;
	char			*ret;

	if (!n || n == 0)
		return (ft_utoazero());
	ssize = n;
	size = 0;
	len = ssize;
	while (len > 0)
	{
		size++;
		len /= 10;
	}
	ret = ft_utoawrite(ssize, size);
	return (ret);
}
