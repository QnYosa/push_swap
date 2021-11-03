/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/03 23:24:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	count_under_mid(t_list *sender, int mid)
{
	int	under;
	t_node	*iterator;

	under = 0;
	iterator = sender->head;
	while (iterator != NULL)
	{
		if (iterator->number <=  mid)
			under++;
		iterator = iterator->next;
	}
	return (under);
}

void	push_under_mid(t_list *sender, t_list *receiver, int mid, \
	t_mediane_nodes *median)
{
	int	i;
	int	under;

	median->a_side = 0;
	median->b_side = 0;
	under = count_under_mid(sender, mid);
	i = 0;
	while (i < under)
	{
		if (sender->head->number <= mid)
		{
			push_first(sender, receiver);
			median->b_side++;
			if (receiver->head->next != NULL)
			{
				if (receiver->head->number < receiver->head->next->number)
					swap(receiver->head, receiver->head->next, 'b');
			}
			i++;
		}
		else
		{
			ra_list(sender, 'a');
			median->a_side++;
		}
	}
}

int		find_mid(t_list *stack)
{
	int 				mid;
	int					*tab;
	t_node				*iterator;
	unsigned int		i;

	tab = malloc(sizeof(int) * stack->length);
	i = 0;
	iterator = stack->head;
	while (iterator != NULL)
	{
		tab[i] = iterator->number;
		i++;
		iterator = iterator->next;
	}
	ft_sort_int_tab(tab, stack->length);
		mid = tab[(stack->length / 2) - 1];
	return (mid);
}