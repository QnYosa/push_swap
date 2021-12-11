/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_rec_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:22:02 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/11 23:13:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	out_is_sorted(t_list *sender, t_list *receiver, long *tab)
{
	if (is_next(receiver, sender))
	{
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
		return (0);
	}
	if (tab[3] == sender->head->next->number)
	{
		swap(sender->head, sender->head->next, sender->c, receiver->l_co);
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
		return (0);
	}
	return (1);
}

long	elif(t_list *sender, t_list *receiver, long *tab, long *touched)
{
	if (is_next(receiver, sender) && touched[3] == 1)
	{
		push_first(sender, receiver);
		if (touched[0] == 1)
		{
			rra_list(receiver, receiver->c, receiver->l_co);
		}
		else
			push_first(sender, receiver);
		free(tab);
		free(touched);
		return (0);
	}
	else
	{
		push_first(sender, receiver);
		ra_list(receiver, receiver->c, receiver->l_co);
	}
	return (1);
}

long	cond_bottom(t_list *sender, t_list *receiver, long *tab, long *touched)
{
	if (sender->head->number == tab[0])
	{
		push_first(sender, receiver);
		ra_list(receiver, receiver->c, receiver->l_co);
		touched[0] = 1;
	}
	else if (sender->head->number == tab[1])
	{
		if (!elif(sender, receiver, tab, touched))
			return (0);
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
		swap(receiver->head, receiver->head->next, \
		receiver->c, receiver->l_co);
	return (1);
}
