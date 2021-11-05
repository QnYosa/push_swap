/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/05 20:16:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

//b_size
int	find_index_tab(int *tab, int number, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (tab[i] == number)
			return (i);
		i++;
	}
	return (i);
}

void	empty_mid(t_list *stack_b, t_list *stack_a, int length)
{
	int	i;
	int	*sorted;
	//int	index;
	t_node	*iter;
	
	iter = stack_b->head;
	sorted = malloc(sizeof(int) * length);
	if (!sorted)
		exit (0);
	i = 0;
	while (i < length && iter)
	{
		sorted[i] = iter->number;
		i++;
		iter = iter->next;
	}
	ft_sort_int_tab(sorted, length);
	iter = stack_b->head;
	i = 0;
	while (i < length && iter->next)
	{
		//index tab, number
		//index = find_index_tab(sorted, )
		if (stack_b->head->number == sorted[0])
		{
			push_first(stack_b, stack_a);
			ra_list(stack_a, 'a');
		}
		else if (stack_b->head->number == sorted[1])//sorted[index]
			ra_list(stack_b, 'b');
		else if (stack_b->head->number == sorted[2])
			ra_list(stack_b, 'b');
		else if (stack_b->head->number == sorted[3])
			push_first(stack_b, stack_a);
		else if (stack_b->head->number == sorted[4])
			push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		i++;
		/*iter = iter->next;*/
	}
		rra_list(stack_b, 'b');
		rra_list(stack_b, 'b');
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		push_first(stack_b, stack_a);
		push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		rra_list(stack_a, 'a');
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
		list_display(stack_a, stack_b);

		//printf("HOLA MIDDLE %d\n b_side %d\n", middle, mid->head->b_side);
		add_mid_index(mid);
	}
	mediane_display(mid);
	five_arg_maestro(stack_a);
	empty_mid(stack_b, stack_a, mid->head->b_side);
	list_display(stack_a, stack_b);
	//printf("%d\n", stack_a->length + stack_b->length);
}
