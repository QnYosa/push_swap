/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:02:59 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/05 23:25:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_node	*new_node(t_node *new, t_node *tmp, char *content, t_list *list)
{
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = ft_atoi(content);
	tmp->next->previous = new;
	tmp->previous->next = new;
	new->previous = tmp->previous;
	new->next = tmp;
	list->length++;
	return (new);
}

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
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

	if (!list)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = ft_atoi(content);
	node->next = NULL;
	if (list->tail == NULL)
	{
		node->previous = NULL;
		list->tail = node;
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

t_list	*list_start(t_list *list, char *content)
{
	t_node	*new_node;

	if (!list)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->number = ft_atoi(content);
	new_node->previous = NULL;
	if (list->tail == NULL)
	{
		new_node->next = NULL;
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->head->previous = new_node;
		new_node->next = list->head;
		list->head = new_node;
	}
	list->length++;
	return (list);
}

t_list	*list_insert(t_list *list, char *content, int position)
{
	t_node	*tmp;
	int		i;
	t_node	*new;

	if (!list)
		return (NULL);
	tmp = list->head;
	i = 1;
	while (tmp != NULL && i <= position)
	{
		if (position == i)
		{
			if (tmp->next == NULL || tmp->previous == NULL)
				list = list_insert_norm(tmp, list, content);
			else
				new = malloc_node_norm(tmp, new, list, content);
		}
		else
			tmp = tmp->next;
		i++;
	}
	return (list);
}
