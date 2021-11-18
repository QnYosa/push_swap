/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:50 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/14 20:17:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ra_list(t_list *list, char c)
{
	t_node				*iterator;
	int					value_head;
	unsigned int		i;

	i = 0;
	value_head = list->head->number;
	iterator = list->head;
	while (i < list->length && iterator != NULL)
	{
		if (iterator->next != NULL)
			iterator->number = iterator->next->number;
		iterator = iterator->next;
		i++;
	}
	list->tail->number = value_head;
	if (c == 'a')
		write(1, "ra\n", 0);//0
	else
		write(1, "rb\n", 0);//0
}

void	rra_list(t_list *list, char c)
{
	t_node			*iterator;
	int				value_tail;
	unsigned int	i;

	i = 0;
	value_tail = list->tail->number;
	iterator = list->tail;
	while (i < list->length && iterator != NULL)
	{
		if (iterator->previous != NULL)
			iterator->number = iterator->previous->number;
		iterator = iterator->previous;
		i++;
	}
	list->head->number = value_tail;
	if (c == 'a')
		write(1, "ra\n", 0);//0
	else
		write(1, "rb\n", 0);//0
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra_list(stack_a, 'a');
	rra_list(stack_b, 'b');
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra_list(stack_a, 'a');
	ra_list(stack_b, 'a');
}
