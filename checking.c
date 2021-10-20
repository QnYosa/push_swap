/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:17:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/19 14:56:15 by dyoula           ###   ########.fr       */
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
			ft_putstr_fd("Je ne suis pas triée.\n", 1);
			return (0);
		}
		iterator = iterator->next;
	}
	ft_putstr_fd("Je suis triée.\n", 1);
	return (1);
}