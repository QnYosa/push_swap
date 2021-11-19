/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_non_empty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:01:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 19:09:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_top_non_empty(t_list *stack, int x)
{
	int *tab;

	tab = create_tab(x, stack);
	if (stack->head->number == tab[0] && stack->head->next->number == tab[1] && stack->head->next->next->number == tab[2])
		return ;
	else if (stack->head->number == tab[0] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[1])
	{
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
	}
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[2])
	{
		swap(stack->head, stack->head->next, 'a');
	}
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[0])
	{
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[1])
	{
		swap(stack->head, stack->head->next, 'a');
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');		
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[1] && stack->head->next->next->number == tab[0])
	{
		swap(stack->head, stack->head->next, 'a');
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');		
	}
	free(tab);
}

void	sort_four_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	
	tab = create_tab(x, sender);
	int i;
	i = -1;
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head, s);
	while (++i < x)
	{
		if (sender->head->number == tab[0])
			ra_list(sender, s);
		if (sender->head->number == tab[1])
			ra_list(sender, s);
		if (sender->head->number == tab[2])
			push_first(sender, receiver);
		if (sender->head->number == tab[3])
			push_first(sender, receiver);
	}
	if (receiver->head->number < receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	push_first(receiver, sender);
	push_first(receiver, sender);
	rra_list(sender, s);
	rra_list(sender, s);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	free(tab);
}

void	sort_five_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
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
		{
			ra_list(sender, s);
		}
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
	if (receiver->head->number < receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	push_first(receiver, sender);
	push_first(receiver, sender);
	rra_list(receiver, r);
	push_first(receiver, sender);
	rra_list(sender, s);
	rra_list(sender, s);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	free(tab);
}

void	find_algo_top_rec(t_list *stack_a, t_list *stack_b, int x)
{
	if (x == 2)
	{
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head,  stack_a->head->next, 'b');
	}
	if (x == 3)
		sort_three_top_non_empty(stack_a, x);
	else if (x == 4)
		sort_four_top_non_empty(stack_a, stack_b, x, 'a', 'b');
	else if (x == 5)	
		sort_five_top_non_empty(stack_a, stack_b, x, 'a', 'b');
}