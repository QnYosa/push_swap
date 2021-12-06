/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:17:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:46:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	is_sorted(t_list *stack)
{
	t_node	*iterator;

	iterator = stack->head;
	while (iterator != NULL)
	{
		if (iterator->next != NULL && iterator->number > iterator->next->number)
		{
			//ft_putstr_fd("Error\n", 1);
			return (0);
		}
		iterator = iterator->next;
	}
	return (1);
}

long	is_sorted_end(t_list *stack)
{
	t_node	*iterator;

	iterator = stack->head;
	while (iterator != NULL)
	{
		if (iterator->next != NULL && iterator->number > iterator->next->number)
		{
			//ft_putstr_fd("Error\n", 1);
			return (0);
		}
		iterator = iterator->next;
	}
	return (1);
}
