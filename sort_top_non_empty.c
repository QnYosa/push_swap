/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_non_empty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:01:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:37:50 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_top_non_empty(t_list *stack, long x)
{
	long	*tab;

	tab = create_tab(x, stack);
	// printf("%d, %d, %d\n", tab[0], tab[1],tab[2]);
	if (stack->head->number == tab[0] && stack->head->next->number == tab[1] \
		&& stack->head->next->next->number == tab[2])
		return ;
	else if (stack->head->number == tab[0] && stack->head->next->number \
	== tab[2] && stack->head->next->next->number == tab[1])
	{
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
	}
	else if (stack->head->number == tab[1] && stack->head->next->number \
	== tab[0] && stack->head->next->next->number == tab[2])
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	s_t_t_n_e(stack, tab);
	free(tab);
}

void	sort_four_top_non_empty(t_list *sender, t_list *receiver, long x)
{
	long	*tab;
	long	*touched;
	long	i;
	long	ra;

	ra = 0;
	touched = malloc(sizeof(long) * x);
	tab = malloc(sizeof(long) * x);
	tab = create_tab(x, sender);
	if (!touched || !tab)
		return ;
	i = -1;
	touched = is_next_top_a(tab, touched, x, sender);
	//list_display(sender, receiver);
	// printf("%d, %d, %d, %d\n", tab[0], tab[1],tab[2],tab[3]);
	if (touched[3] == 1)
	{
		// printf("%d\n", tab[3]);
		sort_three_top_non_empty(sender, x - 1);
		free(tab);
		free(touched);
		return ;
	}
	else
	{
		// printf("%d, %d, %d, %d\n", tab[0], tab[1],tab[2],tab[3]);
		while (++i < x)
		{
			if (ra_opt_stne(ra, sender, tab, x))
				return ;
			if (sender->head->number == tab[0])
			{
				ra_list(sender, sender->c, sender->l_co);
				ra++;
			}
			if (sender->head->number == tab[1])
			{
				ra_list(sender, sender->c, sender->l_co);
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
	s_f_t_n_e(sender, receiver, tab, ra);
	free(tab);
}

void	find_algo_top_rec(t_list *stack_a, t_list *stack_b, long x)
{
	if (x == 2)
	{
		// printf("%d, %d\n", stack_a->head->number, stack_a->head->next->number);
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, 'a', stack_a->l_co);
	}
	if (x == 3)
		sort_three_top_non_empty(stack_a, x);
	else if (x == 4)
		sort_four_top_non_empty(stack_a, stack_b, x);
}
