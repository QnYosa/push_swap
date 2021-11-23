/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:17:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 22:05:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_node	*iterator;

	iterator = stack->head;
	while (iterator != NULL)
	{
		if (iterator->next != NULL && iterator->number < iterator->next->number)
		{
			ft_putstr_fd("je suis pas triee\n", 1);
			return (0);
		}
		iterator = iterator->next;
	}
	ft_putstr_fd("je suis triee\n", 1);
	return (1);
}

int	is_sorted_end(t_list *stack)
{
	t_node	*iterator;

	iterator = stack->head;
	while (iterator != NULL)
	{
		if (iterator->next != NULL && iterator->number > iterator->next->number)
		{
			ft_putstr_fd("je suis pas triee\n", 1);
			printf("je bug a cause de %d\n", iterator->number);
			return (0);
		}
		iterator = iterator->next;
	}
	ft_putstr_fd("je suis triee\n", 1);
	return (1);
}
