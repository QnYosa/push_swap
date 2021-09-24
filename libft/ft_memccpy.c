/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:12:27 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/27 15:45:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					i;
	const unsigned char		*str;
	unsigned char			*des;

	str = src;
	des = dest;
	i = 0;
	while (i < n)
	{
		des[i] = str[i];
		if (des[i] == (unsigned char)c)
		{
			return (&dest[i + 1]);
		}
		i++;
	}
	return (0);
}
