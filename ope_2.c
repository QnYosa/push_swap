/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:50 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/11 23:25:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ra_list(t_list *list, char c, t_write *l_co)
{
	t_node				*iterator;
	int					value_head;
	unsigned int		i;

	if (!list->head || !list->head->next)
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
		add_commands_start(l_co, "ra\n");
	else if (c == 'b')
	{
		if (list->length > 0)
			add_commands_start(l_co, "rb\n");
	}
}

void	rra_list(t_list *list, char c, t_write *l_co)
{
	t_node			*iterator;
	long			value_tail;
	unsigned int	i;

	if (!list->head || !list->head->next)
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
	if (c == 's')
		return ;
	if (c == 'a')
		add_commands_start(l_co, "rra\n");
	else
	{
		if (list->length > 0)
			add_commands_start(l_co, "rrb\n");
	}
}

void	rr_91(t_list *a, t_list *b)
{
	if (a->length > 1)
		ra_list(a, 's', a->l_co);
	if (b->length > 1)
		ra_list(b, 's', a->l_co);
	add_commands_start(a->l_co, "rr\n");
}

void	rrr(t_list *a, t_list *b)
{
	if (a->length > 1)
		rra_list(a, 's', a->l_co);
	if (b->length > 1)
		rra_list(b, 's', a->l_co);
	add_commands_start(a->l_co, "rrr\n");
}
