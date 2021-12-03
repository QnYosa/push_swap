/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/03 22:17:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	init_touched(int *tab, int size)
{
	int	i;

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

void	sort_four_non_empty(t_list *sender, t_list *receiver, int x, \
char s, char r)
{
	int	*tab;
	int	i;
	int	*touched;

	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	i = -1;
	if (!tab)
		return ;
	if (is_next(receiver, sender))
	{
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, s, r);
		return ;
	}
	init_touched(touched, x);
	while (++i < x)
	{
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r, receiver->l_co);
		if (sender->head->number == tab[0])
		{
			push_first(sender, receiver);
			ra_list(receiver, r, receiver->l_co);
			touched[0] = 1;
		}
		else if (sender->head->number == tab[1])
		{
			if (is_next(receiver, sender) && touched[3] == 1)
			{
				push_first(sender, receiver);
				if (touched[0] == 1)
					rra_list(receiver, receiver->c, receiver->l_co);
				else
					push_first(sender, receiver);
				free(tab);
				free(touched);
				return ;
			}
			else
			{
				push_first(sender, receiver);
				ra_list(receiver, r, receiver->l_co);
			}
		}
		else if (sender->head->number == tab[2])
		{
			push_first(sender, receiver);
			touched[2] = 1;
		}
		else if (sender->head->number == tab[3])
		{
			push_first(sender, receiver);
			touched[3] = 1;
		}	
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r, receiver->l_co);
	}
	if (receiver->length > 1)
		rra_list(receiver, r, receiver->l_co);
	if (receiver->length > 1)
		rra_list(receiver, r, receiver->l_co);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, receiver->c, receiver->l_co);
	free(tab);
	free(touched);
}

void	sort_five_non_empty(t_list *sender, t_list *receiver, int x, \
char s, char r)
{
	int	*tab;
	int	i;
	int	*touched;
	int	rad;

	rad = 0;
	tab = create_tab(x, sender);
	touched = malloc(sizeof(int) * x);
	if (!tab || !touched)
		return ;
	i = -1;
	if (is_next(receiver, sender))
	{
		push_first(sender, receiver);
		sort_four_non_empty(sender, receiver, x - 1, s, r);
		return ;
	}
	else
	{
		init_touched(touched, x);
		while (++i < x)
		{
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s, receiver->l_co);
				rad++;
			}
			else if (sender->head->number == tab[1])
			{
				ra_list(sender, s, receiver->l_co);
				rad++;
			}
			else if (sender->head->number == tab[2])
			{
				if (is_next(receiver, sender) && touched[4] == 1)
				{
					touched[2] = 1;
					push_first(sender, receiver);
					un_ra_list(sender, rad, sender->c, receiver->l_co);
					push_first(sender, receiver);
					push_first(sender, receiver);
					if (receiver->head->number > receiver->head->next->number)
						swap(receiver->head, receiver->head->next, \
						r, receiver->l_co);
					return ;
				}
				else
				{
					push_first(sender, receiver);
					ra_list(receiver, r, receiver->l_co);
				}
			}
			else if (sender->head->number == tab[3])
			{
				touched[3] = 1;
				push_first(sender, receiver);
			}
			else if (sender->head->number == tab[4])
			{
				push_first(sender, receiver);
				touched[4] = 1;
			}
		}
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, receiver->c, \
			receiver->l_co);
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r, receiver->l_co);
		rra_list(receiver, r, receiver->l_co);
		rra_list(sender, s, receiver->l_co);
		rra_list(sender, s, receiver->l_co);
		if (sender->head->number < sender->head->next->number)
			swap(sender->head, sender->head->next, s, receiver->l_co);
		push_first(receiver, sender);
		push_first(receiver, sender);
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r, receiver->l_co);
		free(tab);
		free(touched);
	}
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, int x)
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
		sort_four_non_empty(stack_b, stack_a, x, stack_b->c, stack_a->c);
	else if (x == 5)
		sort_five_non_empty(stack_b, stack_a, x, stack_b->c, stack_a->c);
}
