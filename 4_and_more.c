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

void	chose_op(t_list *stack_a, t_list *stack_b)
{
	list_display(stack_a, stack_b);
	if (is_max(stack_a, stack_b->head->number))
	{
		write(1, "fuck sydney\n", 12);
		push_first(stack_b, stack_a);
		list_display(stack_a, stack_b);
		rra_list(stack_a);
	}
}

void	small_insertion(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = init_list();
	push_first(stack_a, stack_b);
	chose_algo(4, stack_a);
	chose_op(stack_a, stack_b);
	//one_list_display(stack_a);
	delete_list(&stack_b);
}
