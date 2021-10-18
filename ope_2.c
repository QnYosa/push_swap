/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:53 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/18 23:15:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ra_list(t_list *list)
{
	t_node				*iterator;
	int					value_head;
	unsigned int		i;

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
}

void	rra_list(t_list *list)
{
	t_node			*iterator;
	int				value_tail;
	unsigned int	i;

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
}
