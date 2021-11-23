/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 23:53:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"


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


int	*create_tab(int size, t_list *stack)
{
	int i;
	int	*tab;
	t_node	*node;

	tab = malloc(sizeof(int) * size);
	node = stack->head;
	i = -1;
	while (++i < size && node)
	{
		tab[i] = node->number;
		node = node->next;
	}
	tab = ft_sort_int_tab(tab, size);
	return (tab);
}

void	recursive_sort(t_list *stack_a, t_list *stack_b, int len)
{
	int med_a;
	int	x;

	med_a = find_mid_x(stack_a, len);
	x = push_bajo_mid(stack_a, stack_b, med_a);
	if (len - x <= 5)
	{
		if (len - x == (int)stack_a->length)
			chose_algo(x + 1, stack_a);
		else
			find_algo_top_rec(stack_a, stack_b, len - x);
	}
	else
		recursive_sort(stack_a, stack_b, len - x);
	if (x <= 5)
		find_algo_rec(stack_a, stack_b, x);
	else
		send_b_to_a(stack_b, stack_a, x);
}

void	big_algo_maestro(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = init_list();
	stack_a->tab = create_tab(stack_a->length, stack_a);
	ft_rev_int_tab(stack_a->tab, stack_a->length);
	stack_a->quarter = find_quarter(stack_a);
	stack_a->c = 'a';
	stack_b->c = 'b';
	recursive_sort(stack_a, stack_b, stack_a->length);
	is_sorted_end(stack_a);
	free(stack_a->tab);
	delete_list(&stack_b);
}
