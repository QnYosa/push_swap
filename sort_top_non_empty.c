/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_non_empty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:01:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/26 19:39:25 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_top_non_empty(t_list *stack, int x)
{
	int	*tab;

	tab = create_tab(x, stack);
	if (stack->head->number == tab[0] && stack->head->next->number == tab[1] \
		&& stack->head->next->next->number == tab[2])
		return ;
	else if (stack->head->number == tab[0] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[1])
	{
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
	}
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[2])
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[0])
	{
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[1])
	{
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);		
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[1] && stack->head->next->next->number == tab[0])
	{
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	}
	free(tab);
}

void	sort_four_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int 	*tab;
	int		*touched;
	int		i;
	int		ra;
	(void)	r;

	ra = 0;
	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	if (!touched || !tab)
		return ;
	i = -1;
	touched = is_next_top_a(tab, touched, x, sender);
	if (touched[3] == 1)
	{
		sort_three_top_non_empty(sender, x - 1);
		free(touched);
		return ;
	}
	else
	{
		while (++i < x)
		{
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s, sender->l_co);
				ra++;
			}
			if (sender->head->number == tab[1])
			{
				ra_list(sender, s, sender->l_co);
				ra++;
			}
			if (sender->head->number == tab[2])
			{
				if (receiver->head->number != tab[3] && ra != 2)
					push_first(sender, receiver);
				else
					swap(sender->head, sender->head->next, sender->c, sender->l_co);
			}
			if (sender->head->number == tab[3])
			{
				if (receiver->head->number != tab[2] && ra != 2)
					push_first(sender, receiver);
				else
					swap(sender->head, sender->head->next, sender->c, sender->l_co);
			}
		}
	}
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, r, sender->l_co);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, s, sender->l_co);
	if (receiver->head->number == tab[3] || receiver->head->number == tab[2])
		push_first(receiver, sender);
	if (receiver->head->number == tab[3] || receiver->head->number == tab[2])
		push_first(receiver, sender);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, s, sender->l_co);
	un_ra_list(sender, ra, sender->c, sender->l_co);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, s, sender->l_co);
	free(tab);
}

void	sort_five_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int	*tab;
	int	i;
	int	*touched;
	int	ra;

	ra = 0;
	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	if (!tab || !touched)
		return ;
	i = -1;
	touched = is_next_top_a(tab, touched, x, sender);
	if (touched[4] == 1)
	{
		sort_four_top_non_empty(sender, receiver, x, s, r);
		return ;
	}
	else
	{
		while (++i < x)
		{
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s, sender->l_co);
			}
			else if (sender->head->number == tab[1])
				ra_list(sender, s, sender->l_co);
			else if (sender->head->number == tab[2])
			{
				push_first(sender, receiver);
				ra_list(receiver, r, sender->l_co);
			}
			else if (sender->head->number == tab[3])
				push_first(sender, receiver);
			else if (sender->head->number == tab[4])
				push_first(sender, receiver);
		}
		if (receiver->head->number < receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r, sender->l_co);
		push_first(receiver, sender);
		push_first(receiver, sender);
		rra_list(receiver, r, sender->l_co);
		push_first(receiver, sender);
		rra_list(sender, s, sender->l_co);
		rra_list(sender, s, sender->l_co);
		if (sender->head->number > sender->head->next->number)
			swap(sender->head, sender->head->next, s, sender->l_co);
		free(tab);
	}
}

void	find_algo_top_rec(t_list *stack_a, t_list *stack_b, int x)
{
	if (x == 2)
	{
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, 'b', stack_a->l_co);
	}
	if (x == 3)
		sort_three_top_non_empty(stack_a, x);
	else if (x == 4)
		sort_four_top_non_empty(stack_a, stack_b, x, 'a', 'b');
	else if (x == 5)
		sort_five_top_non_empty(stack_a, stack_b, x, 'a', 'b');
}
