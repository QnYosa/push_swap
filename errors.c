/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:18:34 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/25 18:18:39 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_space_or_digit(char c)
{
	int	i;

	i = 0;
	while (SPACESDIGITS[i])
	{
		if (SPACESDIGITS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	errors_main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_space_or_digit(argv[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
