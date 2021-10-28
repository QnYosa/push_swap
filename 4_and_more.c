/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:07:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/24 18:12:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

int	is_max(t_list *stack_a, int n)
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

int	find_min(t_list *stack_a)
{
	int		min;
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

int	find_index_min(t_list *stack, int min)
{
	t_node	*tmp;
	int		index;

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

void	find_op_min(t_list *stack_a, int index, t_list *stack_b)
{
	if (index == 0)
		push_first(stack_a, stack_b);
	else if (index == 1)
	{
		swap(stack_a->head, stack_a->head->next, 'a');
		push_first(stack_a, stack_b);		
	}
	else if (index == 2)
	{
		ra_list(stack_a, 'a');
		ra_list(stack_a, 'a');
	}
	else
	{
		rra_list(stack_a, 'a');
		push_first(stack_a, stack_b);
	}
}

void	small_insertion(t_list *stack_a)
{
	t_list	*stack_b;
	int min;
	int	index;

	stack_b = init_list();
	min = find_min(stack_a);
	index = find_index_min(stack_a, min);
	find_op_min(stack_a, index, stack_b);
	three_arg_maestro(stack_a);
	push_first(stack_b, stack_a);
	one_list_display(stack_a);
	delete_list(&stack_b);
}
