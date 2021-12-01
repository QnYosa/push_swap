/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:03:53 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/30 23:21:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	b_which_op_max(int index, t_list *stack)
{
	if (index == 0)
		ra_list(stack, 'a', stack->l_co);
	else if (index == 1)
		rra_list(stack, 'a', stack->l_co);
}

void	b_three_arg(t_list *stack_a)
{
	int	max;
	int	index;

	max = find_max(stack_a);
	index = find_index_max(stack_a, max);
	b_which_op_max(index, stack_a);
	if (stack_a->head->number > stack_a->head->next->number)
		swap(stack_a->head, stack_a->head->next, 'a', stack_a->l_co);
}
