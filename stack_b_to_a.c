/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:59:08 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/10 23:06:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	push_above_mid_a(t_list *sender, t_list *receiver, int mid)
{
	int	i;
	t_node	*iter;
	int	arriba;

	arriba = count_above_mid(sender, mid);
	iter = sender->head;
	i = -1;
	list_display(receiver, sender);
	printf("salut number %d\n", iter->next->number);
	while (++i < arriba && iter)
	{
		if (iter->number > mid)
		{
	 		push_first(sender, receiver);
		}
		else if (iter->number <= mid)
		{
			printf("mid = %d && head = %d arriba = %d\n", mid, iter->number, arriba);
			ra_list(sender, 'b');
		}
		iter = iter->next;
	}
	return (arriba);
}

void	send_b_to_a(t_list *sender, t_list *receiver)
{
	int med_x;
	int above;

	med_x = find_mid(sender);
	above = push_above_mid_a(sender, receiver, med_x);
	if (above > 5)
		send_b_to_a(sender, receiver);
	else if (above <= 5)
		chose_algo(above + 1, sender);
}
