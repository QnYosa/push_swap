/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:50 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:30:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	g_ra_list(t_list *list, char c)
{
	t_node				*iterator;
	long				value_head;
	unsigned int		i;

	if (list->length < 2)
		return ;
	i = 0;
	value_head = list->head->number;
	iterator = list->head;
	while (i < list->length && iterator != NULL)
	{
		if (iterator->next != NULL)
			iterator->number = iterator->next->number;
		iterator = iterator->next;
		i++;
	}
	list->tail->number = value_head;
	if (c == 's')
		return ;
	else if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	g_rra_list(t_list *list, char c)
{
	t_node			*iterator;
	long			value_tail;
	unsigned int	i;

	if (list->length < 2)
		return ;
	i = 0;
	value_tail = list->tail->number;
	iterator = list->tail;
	while (i < list->length && iterator != NULL)
	{
		if (iterator->previous != NULL)
			iterator->number = iterator->previous->number;
		iterator = iterator->previous;
		i++;
	}
	list->head->number = value_tail;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
