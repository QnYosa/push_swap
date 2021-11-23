/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:32:25 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 23:39:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	find_op_five(t_list *stack_a, int index, t_list *stack_b)
{
	if (index == 1)
		swap(stack_a->head, stack_a->head->next, stack_a->c);
	else if (index == 2)
	{
		ra_list(stack_a, stack_a->c);
		ra_list(stack_a, stack_a->c);
	}
	else if (index == 3)
	{
		rra_list(stack_a, stack_a->c);
		rra_list(stack_a, stack_a->c);
	}
	else if (index == 4)
		rra_list(stack_a, stack_a->c);
	push_first(stack_a, stack_b);
}

void	five_arg_maestro(t_list *stack_a)
{
	t_list	*stack_b;
	int		min;
	int		index;

	stack_b = init_list();
	min = find_min(stack_a);
	index = find_index_min(stack_a, min);
	find_op_five(stack_a, index, stack_b);
	small_insertion(stack_a);
	push_first(stack_b, stack_a);
	delete_list(&stack_b);
}
