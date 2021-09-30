/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:02:59 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/30 19:54:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_list	*list_end(t_list *list, char *content)
{
	t_node	*node;

	if (!p_list)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->number = ft_atoi(content);
	node->next = NULL;
	if (list->last == NULL)
	{
		node->previous = NULL;
		list->end = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
	}
	list->length++;
	return (list);
}

t_list	*list_start(t_list list, char *content)
{
	t_node	*new_node;

	if (!list)
		return (NULL);
	new_node = malloc(sizeof(*node));
	if (!new_node)
		return (NULL);
	new_node->number = ft_atoi(content);
	new_node->previous = NULL;
	if (list->tail == NULL)
	{
		new_node->next = NULL;
		list->head = new_node;
		list->tail = node;
	}
	else
	{
		list->head->previous = node;
		new_node->next-> = list->head;
		list->head = new_node;
	}
	list->length++;
	return (list);
}

t_list	*list_insert(t_list *list, int number, int position)
{
	t_node	*tmp;

	if (!list)
		return (NULL);
	
}