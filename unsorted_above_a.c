/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_above_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:09:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/08 00:09:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	index_b_side(int *tab, int mid, int b_side)
{
	int	i;
	int	under_mid;

	i = -1;
	under_mid = 0;
	while (++i < b_side)
	{
		if (tab[i] < mid)
			under_mid++;
	}
	return (under_mid);
}

int	to_empty_unsorted_top(int b_side, t_list *sender, t_list *receiver)
{
	int	i;
	int	*tab;
	int ra;
	t_node *node;
	int	mid;

	ra = 0;
	i = 0;
	tab = malloc(sizeof(int) * b_side);
	node = sender->head;
	if (!tab)
		exit(-1);
	while (i < b_side && node)
	{
		tab[i] = node->number;
		node = node->next;
		i++;
	}
	if (b_side % 2 == 0)
		mid = tab[(b_side / 2) - 1];
	else
		mid = tab[(b_side / 2)];
	i = 0;
	ft_sort_int_tab(tab, b_side);
	while (i < b_side)//
	{
		if (sender->head->number > mid)
		{
			if (receiver->head->number > receiver->head->next->number)
				swap(receiver->head, receiver->head->next, 'b');
			ft_putstr_fd("push: ",1);
			ft_putnbr_fd(sender->head->number, 1);
			ft_putstr_fd("\n", 1);
			push_first(sender, receiver);
		}			
		else
		{
			ft_putstr_fd("ra:", 1);
			ft_putnbr_fd(sender->head->number, 1);
			ft_putstr_fd("\n", 1);	
			ra_list(sender, 'a');
			ra++;
		}
		list_display(receiver, sender);
		i++;
	}
	i = -1;
	while (++i < ra)
	{
		if (sender->head->next)
		{
			rra_list(sender, 'b');
			if (sender->head->number < sender->head->next->number)
				swap(sender->head, sender->head->next, 'b');
			if (receiver->head->number > receiver->head->next->number)
				swap(receiver->head, receiver->head->next, 'b');		
		}
		push_first(sender,receiver);
	}
	free(tab);
	return (index_b_side(tab, mid,b_side));
}
