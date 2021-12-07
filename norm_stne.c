/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_stne.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:26:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/07 18:40:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	s_t_t_n_e_2(t_list *stack, long *tab)
{
	if (stack->head->number == tab[2] && stack->head->next->number \
	== tab[1] && stack->head->next->next->number == tab[0])
	{
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	}	
}

void	s_t_t_n_e(t_list *stack, long *tab)
{
	if (stack->head->number == tab[1] && stack->head->next->number \
	== tab[2] && stack->head->next->next->number == tab[0])
	{
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
	}
	else if (stack->head->number == tab[2] \
	&& stack->head->next->number == tab[0] \
	&& stack->head->next->next->number == tab[1])
	{
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		ra_list(stack, 'a', stack->l_co);
		swap(stack->head, stack->head->next, 'a', stack->l_co);
		rra_list(stack, 'a', stack->l_co);
	}
	s_t_t_n_e_2(stack, tab);
}

void	s_f_t_n_e(t_list *sender, t_list *receiver, long *tab, long ra)
{
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, sender->c, sender->l_co);
	if (receiver->head->number == tab[3] || receiver->head->number == tab[2])
		push_first(receiver, sender);
	if (receiver->head->number == tab[2] || receiver->head->number == tab[3])
		push_first(receiver, sender);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, sender->c, sender->l_co);
	un_ra_list(sender, ra, sender->c, sender->l_co);
	if (sender->head->number > sender->head->next->number)
		swap(sender->head, sender->head->next, sender->c, sender->l_co);
}

long	ra_opt_stne(long ra, t_list *sender, long *tab, long x)
{
	if (ra == 2)
	{
		if (sender->head->number == tab[4] \
		&& sender->head->next->number == tab[3])
		{
			swap(sender->head, sender->head->next, \
			sender->c, sender->l_co);
			un_ra_list(sender, ra, sender->c, sender->l_co);
			sort_three_top_non_empty(sender, x - 1);
			return (1);
		}
	}
	return (0);
}
