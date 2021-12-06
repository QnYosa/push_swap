/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:03:53 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:09:04 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	find_max(t_list *stack_a)
{
	long		max;
	t_node	*tmp;

	tmp = stack_a->head;
	max = stack_a->head->number;
	while (tmp->next != NULL)
	{
		if (max < tmp->next->number && tmp->next)
			max = tmp->next->number;
		tmp = tmp->next;
	}
	return (max);
}

long	find_index_max(t_list *stack, long max)
{
	t_node	*tmp;
	long		index;

	if (!stack)
		exit(0);
	tmp = stack->head;
	index = 0;
	while (tmp)
	{
		if (tmp->number == max)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	which_op_max(long index, t_list *stack)
{
	if (index == 0)
		g_ra_list(stack, 'a');
	else if (index == 1)
		g_rra_list(stack, 'a');
}

void	three_arg_maestro(t_list *stack_a)
{
	long	max;
	long	index;

	max = find_max(stack_a);
	index = find_index_max(stack_a, max);
	which_op_max(index, stack_a);
	if (stack_a->head->number > stack_a->head->next->number)
		g_swap(stack_a->head, stack_a->head->next, 'a');
}
