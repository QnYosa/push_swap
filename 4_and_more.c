/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:07:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/07 15:41:07 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	is_max(t_list *stack_a, long n)
{
	t_node	*tmp;

	tmp = stack_a->head;
	while (tmp->next != NULL)
	{
		if (n < tmp->next->number && tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	find_min(t_list *stack_a)
{
	long	min;
	t_node	*tmp;

	tmp = stack_a->head;
	min = stack_a->head->number;
	while (tmp->next != NULL)
	{
		if (min > tmp->next->number && tmp->next)
			min = tmp->next->number;
		tmp = tmp->next;
	}
	return (min);
}

long	find_index_min(t_list *stack, long min)
{
	t_node		*tmp;
	long		index;

	if (!stack)
		exit(0);
	tmp = stack->head;
	index = 0;
	while (tmp)
	{
		if (tmp->number == min)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	find_op_min(t_list *stack_a, long index, t_list *stack_b)
{
	if (index == 1)
		g_swap(stack_a->head, stack_a->head->next, stack_a->c);
	else if (index == 2)
	{
		g_ra_list(stack_a, stack_a->c);
		g_ra_list(stack_a, stack_a->c);
	}
	else if (index == 3)
		g_rra_list(stack_a, stack_a->c);
	g_push_first(stack_a, stack_b);
}

void	small_insertion(t_list *stack_a)
{
	t_list		*stack_b;
	long		min;
	long		index;

	stack_b = init_list();
	stack_b->c = 'b';
	min = find_min(stack_a);
	index = find_index_min(stack_a, min);
	find_op_min(stack_a, index, stack_b);
	three_arg_maestro(stack_a);
	g_push_first(stack_b, stack_a);
	delete_list(&stack_b);
}
