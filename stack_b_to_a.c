/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:59:08 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 23:36:15 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	is_in_tab(int n, int *tab)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (n == tab[i])
			return (1);
	}
	return (0);
}

int	push_above_mid_a(t_list *sender, t_list *receiver, int mid)
{
	int				i;
	int				arriba;
	t_node			*iter;

	arriba = 0;
	iter = sender->head;
	i = -1;
	while (++i < (int)sender->length && iter->next)
	{
		arriba -= is_next(sender, receiver);
		if (iter->number > mid)
		{
			push_first(sender, receiver);
			if (receiver->head->number > receiver->head->next->number)
				swap(receiver->head, receiver->head->next, 'a');
			arriba++;
		}
		else if (iter->number <= mid)
			ra_list(sender, 'b');
		iter = sender->head;
	}
	return (arriba);
}

void	send_b_to_a(t_list *sender, t_list *receiver, int x)
{
	int	med_x;
	int	above;

	med_x = find_mid_x(sender, x);
	above = push_above_mid_x(sender, receiver, med_x, x);
	if (above <= 5)
		find_algo_top_rec(receiver, sender, above);
	else
		recursive_sort(receiver, sender, above);
	if (x - above <= 5)
		find_algo_rec(receiver, sender, x - above);
	else
		send_b_to_a(sender, receiver, x - above);
}
