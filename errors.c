/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:18:34 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/24 18:00:48 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	letters_here(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (argv[i])
		{
			if ((*argv[i] < '0' || *argv[i] > '9' || (*argv[i] < 9)
					|| *argv[i] > 13 || *argv[i] != 32) && *argv[i] != '-'
				&& *argv[i] != '+')
			{
				printf("on a une lettre");
				return (0);
			}
			argv[i]++;
		}
		i++;
	}
	return (1);
}

int	errors_main(int argc, char **argv)
{
	// faire split
	if (!letters_here(argc, argv))
		return (0);
	return (1);
}
