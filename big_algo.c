/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/08 16:00:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

long	find_index_tab(long *tab, long number, long length)
{
	long	i;

	i = 0;
	while (i < length)
	{
		if (tab[i] == number)
			return (i);
		i++;
	}
	return (i);
}

long	*create_tab(long size, t_list *stack)
{
	long		i;
	long		*tab;
	t_node		*node;

	if (!size || !stack)
		return (NULL);
	tab = malloc(sizeof(long) * size);
	if (!tab)
		return (NULL);
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

void	recursive_sort(t_list *stack_a, t_list *stack_b, long len)
{
	long	med_a;
	long	x;

	x = 0;
	med_a = find_mid_x(stack_a, len);
	x = push_bajo_mid(stack_a, stack_b, med_a);
	if (len - x <= 4)
	{
		if (len - x == (long)stack_a->length)
			chose_algo_via_big(x + 1, stack_a);
		else
			find_algo_top_rec(stack_a, stack_b, len - x);
	}
	else
		recursive_sort(stack_a, stack_b, len - x);
	if (x <= 4)
	{
		find_algo_rec(stack_a, stack_b, x);
	}
	else
		send_b_to_a(stack_b, stack_a, x);
}

void	big_algo_maestro(t_list *stack_a)
{
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_b = init_list();
	stack_a->tab = create_tab(stack_a->length, stack_a);
	ft_rev_int_tab(stack_a->tab, stack_a->length);
	stack_a->quarter = find_quarter(stack_a);
	stack_a->c = 'a';
	stack_b->c = 'b';
	//list_display(stack_a, stack_b);
	while (++i < 2)
		ra_list(stack_a, stack_a->c, stack_a->l_co);
	recursive_sort(stack_a, stack_b, stack_a->length);
	while (++i < 15)
		delete_useless(&stack_a->l_co);
	is_sorted_end(stack_a);
	display_commands(stack_a->l_co);
	free(stack_a->tab);
	delete_list(&stack_b);
}
