/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/08 15:32:52 by dyoula           ###   ########.fr       */
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
	{
		// if (receiver->head->number > receiver->head->next->number)
		// 	swap(receiver->head, receiver->head->next, \
		// 	receiver->c, receiver->l_co);
		if (!cond_bottom(sender, receiver, tab, touched))
		{
			return (0);
		}
	}
	return (1);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, long x)
{
	long		*tab;
	long		i;
	long		*touched;

	touched = malloc(sizeof(long) * x);
	tab = create_tab(x, sender);
	i = -1;
	if (!tab)
		return ;
	if (!out_is_sorted(sender, receiver, tab))
		return ;
	init_touched(touched, x);
	if (!loop_sfne(sender, receiver, touched, tab))
		return ;
	rra_list(receiver, receiver->c, receiver->l_co);
	rra_list(receiver, receiver->c, receiver->l_co);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, receiver->c, receiver->l_co);
	free(tab);
	free(touched);
}

// void	sort_four_non_empty(t_list *sender, t_list *receiver, int x)
//
// {
// 	int	*tab;
// 	int	i;
// 	int	*touched;

// 	touched = malloc(sizeof(int) * x);
// 	tab = create_tab(x, sender);
// 	i = -1;
// 	if (!tab)
// 		return ;
// 	if (is_next(receiver, sender))
// 	{
// 		push_first(sender, receiver);
// 		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
// 		return ;
// 	}
// 	if (tab[3] == sender->head->next->number)
// 	{
// 		swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 		push_first(sender, receiver);
// 		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
// 		return ;
// 	}
// 	if (tab[2] == sender->head->number)
// 	{
// 		push_first(sender, receiver);
// 		if (tab[3] == sender->head->next->number)
// 		{
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 			if (receiver->head->number > receiver->head->next->number)
// 				swap(receiver->head, receiver->head->next, \
//				receiver->c, receiver->l_co);
// 		}
// 		else
// 		{
// 			ra_list(sender, sender->c, receiver->l_co);
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 			rra_list(sender, sender->c, receiver->l_co);
// 			rra_list(sender, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 		}
// 		if (sender->head->number < sender->head->next->number)
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 		push_first(sender, receiver);
// 		push_first(sender, receiver);
// 	}
// 	else if (tab[1] == sender->head->number)
// 	{
// 		if (tab[0] == sender->head->next->number)
// 		{
// 		}
// 	}
// 	free(tab);
// 	free(touched);
// }

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
