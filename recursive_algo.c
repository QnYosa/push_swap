/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/10 21:14:20 by dyoula           ###   ########.fr       */
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
	free(tab);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;

	tab = create_tab(x, sender);
	if (sender->head->number == tab[0])
	{
		ra_list(sender, s);
	}
	else if (sender->head->number == tab[1])
		ra_list(sender, s);
	else if (sender->head->number == tab[2])
		push_first(sender, receiver);
 	else if (sender->head->number == tab[3])
		push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head, r);
	ra_list(sender, s);
	ra_list(sender, s);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head, s);
	push_first(sender, receiver);
	push_first(sender, receiver);
	free(tab);
}

void	sort_five_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
// doutes sur le ra_list sur receiver
	tab = create_tab(x, sender);
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
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head, r);
	//ra_list(receiver, r);
	ra_list(sender, s);
	ra_list(sender, s);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head, s);
	push_first(sender, receiver);
	push_first(sender, receiver);
	free(tab);
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, int x)
{

	if (x == 3)
		sort_three_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 4)
		sort_four_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 5)
		sort_five_non_empty(stack_b, stack_a, x, 'b', 'a');
}