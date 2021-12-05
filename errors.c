/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:18:34 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/06 00:13:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

long	is_space_or_digit(char c)
{
	long	i;

	i = 0;
	while (SPACESDIGITS[i])
	{
		if (SPACESDIGITS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long	twins(t_list *l)
{
	t_node	*i;
	t_node	*j;

	i = l->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->number == i->number)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

long	errors_main(long argc, char **argv)
{
	long	i;
	long	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_space_or_digit(argv[i][j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
