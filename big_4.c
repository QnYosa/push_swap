/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:07:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/30 23:05:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	b_find_op_min(t_list *stack_a, int index, t_list *stack_b)
{
	if (index == 1)
		swap(stack_a->head, stack_a->head->next, stack_a->c, stack_a->l_co);
	else if (index == 2)
	{
		ra_list(stack_a, stack_a->c, stack_a->l_co);
		ra_list(stack_a, stack_a->c, stack_a->l_co);
	}
	else if (index == 3)
		rra_list(stack_a, stack_a->c, stack_a->l_co);
	push_first(stack_a, stack_b);
}

void	b_insertion(t_list *stack_a)
{
	t_list	*stack_b;
	int		min;
	int		fuck;

	stack_b = init_list();
	stack_b->c = 'b';
	min = find_min(stack_a);
	fuck = find_index_min(stack_a, min);
	b_find_op_min(stack_a, fuck, stack_b);
	b_three_arg(stack_a);
	push_first(stack_b, stack_a);
	delete_list(&stack_b);
}
