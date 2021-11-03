/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/03 23:02:48 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	empty_mid(t_list *stack_b, t_list *stack_a, int length)
{
	int	i;

	i = 0;
	printf("length = %d\n", length);
	while (i < length)
	{
		push_first(stack_b, stack_a);
		i++;
	}
}

void	big_algo_maestro(t_list *stack_a)
{
	int		middle;
	t_list	*stack_b;
	t_saved_mediane	*mid;

	//printf("LENGTH %d\n", stack_a->length);
	stack_b = init_list();
	mid = init_list_mediane();
	while (stack_a->length > 6)
	{
		list_mediane_start(mid, stack_a);
		middle = mid->head->mediane;
		push_under_mid(stack_a, stack_b, middle, mid->head);
		//printf("HOLA MIDDLE %d\n b_side %d\n", middle, mid->head->b_side);
		add_mid_index(mid);
	}
	mediane_display(mid);
	five_arg_maestro(stack_a);
	empty_mid(stack_b, stack_a, mid->head->b_side);
	list_display(stack_a, stack_b);
	//printf("%d\n", stack_a->length + stack_b->length);
}
