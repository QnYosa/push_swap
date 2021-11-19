/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 19:03:09 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;

	tab = create_tab(x, sender);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	free(tab);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int i;

	tab = create_tab(x, sender);
	i = -1;
	if (!tab)
		return ;
	while (++i < x)
	{
		if (sender->head->number == tab[0])
		{
			push_first(sender, receiver);
			ra_list(receiver, s);
		}
		else if (sender->head->number == tab[1])
		{
			push_first(sender, receiver);
			ra_list(receiver, s);
		}
		else if (sender->head->number == tab[2])
			push_first(sender, receiver);
		else if (sender->head->number == tab[3])
			push_first(sender, receiver);
	}
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	rra_list(receiver, s);
	rra_list(receiver, s);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, 'b');
	free(tab);
}

void	sort_five_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int i;

	tab = create_tab(x, sender);
	if (!tab)
		return ;
	i = -1;
	while (++i < x)
	{
		if (sender->head->number == tab[0])
			ra_list(sender, s);
		else if (sender->head->number == tab[1])
			ra_list(sender, s);
		else if (sender->head->number == tab[2])
		{
			push_first(sender, receiver);
			ra_list(receiver, r);
		}
		else if (sender->head->number == tab[3])
			push_first(sender, receiver);
		else if (sender->head->number == tab[4])
			push_first(sender, receiver);
	}
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	rra_list(receiver, r);
	rra_list(sender, s);
	rra_list(sender, s);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	free(tab);
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, int x)
{
	if (x == 2)
	{
		if (stack_a->head->number < stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, 'b');
		push_first(stack_a, stack_b);
		push_first(stack_a, stack_b);
	}
	if (x == 3)
		sort_three_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 4)
		sort_four_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 5)	
		sort_five_non_empty(stack_b, stack_a, x, 'b', 'a');
}
