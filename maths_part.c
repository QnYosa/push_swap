/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/06 00:35:20 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

long	count_under_mid(t_list *sender, long mid)
{
	long		under;
	t_node	*iterator;

	under = 0;
	iterator = sender->head;
	while (iterator != NULL)
	{
		if (iterator->number <= mid)
			under++;
		iterator = iterator->next;
	}
	return (under);
}

void	un_ra_list(t_list *stack, long x, char c, t_write *l)
{
	long	i;

	i = -1;
	while (++i < x && stack->length > 1)
		rra_list(stack, c, l);
}

long	push_bajo_mid(t_list *sender, t_list *receiver, long mid)
{
	long	i;
	long	k;
	long	under;
	long	pushed;

	under = count_under_mid(sender, mid);
	i = 0;
	k = 0;
	pushed = 0;
	while (i < under && pushed <= under)
	{
		if (sender->head->number <= mid)
		{
			push_first(sender, receiver);
			if (receiver->head->number <= sender->quarter && sender->first_mid == 0 && receiver->head->next != NULL)
				ra_list(receiver, receiver->c, sender->l_co);
			pushed++;
			i++;
		}
		else
		{
			ra_list(sender, sender->c, sender->l_co);
			k++;
		}
	}
	if (sender->first_mid == 1)
		un_ra_list(sender, k, sender->c, sender->l_co);
	if (sender->first_mid == 0)
		sender->first_mid = 1;
	return (under);
}
