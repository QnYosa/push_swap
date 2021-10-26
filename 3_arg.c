/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:03:53 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/24 18:06:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

int	find_max(t_list *stack_a)
{
	int		max;
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

int	find_index_max(t_list *stack, int max)
{
	t_node	*tmp;
	int		index;

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

void	which_op_max(int index, t_list *stack)
{
	if (index == 0)
		ra_list(stack);
	else if (index == 1)
		rra_list(stack);
}

void	three_arg_maestro(t_list *stack_a)
{
	int	max;
	int	index;

	max = find_max(stack_a);
	index = find_index_max(stack_a, max);
	which_op_max(index, stack_a);
	if (stack_a->head->number > stack_a->head->next->number)
		swap_a(stack_a->head, stack_a->head->next);
	one_list_display(stack_a);
}
