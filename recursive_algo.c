/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/11 23:52:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	init_touched(long *tab, long size)
{
	long	i;

	i = -1;
	while (++i < size)
		tab[i] = 0;
}

void	sort_three_non_empty(t_list *sender, t_list *receiver, char s, char r)
{
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s, receiver->l_co);
	push_first(sender, receiver);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s, receiver->l_co);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r, receiver->l_co);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r, receiver->l_co);
}

long	loop_sfne(t_list *sender, t_list *receiver, long *touched, long *tab)
{
	long	i;

	i = -1;
	while (++i < 4)
		if (!cond_bottom(sender, receiver, tab, touched))
			return (0);
	return (1);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, long x)
{
	long		*tab;
	long		i;
	long		*touched;

	touched = malloc(sizeof(long) * x);
	if (!touched)
		return ;
	tab = create_tab(x, sender);
	if (!tab)
	{
		free(touched);
		return ;
	}
	i = -1;
	if (!out_is_sorted(sender, receiver, tab))
	{
		if (touched)
			free(touched);
		if (tab)
			free(tab);
		return ;
	}
	init_touched(touched, x);
	if (!loop_sfne(sender, receiver, touched, tab))
		return ;
	rra_list(receiver, receiver->c, receiver->l_co);
	rra_list(receiver, receiver->c, receiver->l_co);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, receiver->c, receiver->l_co);
	if (tab)
		free(tab);
	if (touched)
		free(touched);
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, long x)
{
	if (x == 2)
	{
		push_first(stack_b, stack_a);
		push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, stack_a->c, stack_a->l_co);
	}
	if (x == 3)
		sort_three_non_empty(stack_b, stack_a, stack_b->c, stack_a->c);
	else if (x == 4)
		sort_four_non_empty(stack_b, stack_a, x);
}
