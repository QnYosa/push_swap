/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:59:08 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/26 19:33:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	push_above_mid_x(t_list *sender, t_list *receiver, int mid, int x)
{
	int	i;
	int	under;
	int	pushed;
	int	stop;

	stop = 0;
	i = -1;
	under = 0;
	pushed = 0;
	while (++i < x)
	{
		if (sender->head->number > mid)
		{
			push_first(sender, receiver);
			pushed++;
		}
		else
		{
			ra_list(sender, sender->c, receiver->l_co);
			under++;
		}
	}
	un_ra_list(sender, under, sender->c, receiver->l_co);
	return (pushed);
}

void	send_b_to_a(t_list *sender, t_list *receiver, int x)
{
	int	med_x;
	int	above;
	int	under;

	med_x = find_mid_x(sender, x);
	above = push_above_mid_x(sender, receiver, med_x, x);
	under = x - above;
	if (above <= 5)
		find_algo_top_rec(receiver, sender, above);
	else
	{
		while (above && is_next_from(receiver, above))
			above--;
		if (above)
			recursive_sort(receiver, sender, above);
	}
	if (under <= 5)
		find_algo_rec(receiver, sender, under);
	else
		send_b_to_a(sender, receiver, under);
}
