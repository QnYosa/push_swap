/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:50 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/26 19:30:36 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ra_list(t_list *list, char c, t_write *l_com)
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
	if (c == 'a')
		add_commands_start(l_com, "ra\n");
	else
		add_commands_start(l_com, "rb\n");
}

void	rra_list(t_list *list, char c, t_write *l_com)
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
	if (c == 'a')
		add_commands_start(l_com, "rra\n");
	else
		add_commands_start(l_com, "rrb\n");
}
