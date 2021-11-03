/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/03 22:26:25 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_saved_mediane	*init_list_mediane(void)
{
	t_saved_mediane	*mids;

	mids= (t_saved_mediane*)malloc(sizeof(t_saved_mediane));
	if (!mids)
		return (NULL);
	mids->length = 0;
	mids->head = NULL;
	mids->tail = NULL;
	return (mids);
}

void	add_mid_index(t_saved_mediane *mid)
{
	t_mediane_nodes	*iterator;
	int				i;

	i = 0;
	iterator = mid->head;
	while (iterator)
	{
		iterator->index = i;
		iterator = iterator->next;
		i++;
	}
}

t_saved_mediane	*list_mediane_start(t_saved_mediane *list, t_list *stack)
{
	t_mediane_nodes	*new_node;

	if (!list)
		return (NULL);
	new_node = malloc(sizeof(t_mediane_nodes));
	if (!new_node)
		return (NULL);
	new_node->mediane = find_mid(stack);
	new_node->min = find_min(stack);
	new_node->max = find_max(stack);
	new_node->previous = NULL;
	if (list->tail == NULL)
	{
		new_node->next = NULL;
		list->head = new_node;
		list->tail = new_node;
		new_node->index = 0;
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

void	mediane_display(t_saved_mediane *mid)
{
	t_mediane_nodes	*iterator;
	
	iterator = mid->head;
	while (iterator)
	{
		printf("||mediane = %d||\n||max = %d||\n||min %d||\n", iterator->mediane, iterator->max, iterator->min);
		printf("||index %d||\n", iterator->index);
		printf("||a_side = %d||\n", iterator->a_side);
		printf("||b_side = %d||\n", iterator->b_side);
		printf("\n");
		iterator = iterator->next;
	}
}
/*
t_mediane_nodes	*new_node(t_mediane_nodes *new, t_mediane_nodes *tmp, char *content, t_list *list)
{
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = ft_atoi(content);
	new->mediane = find_mid(stack_a);
	tmp->next->previous = new;
	tmp->previous->next = new;
	new->previous = tmp->previous;
	new->next = tmp;
	list->length++;
	return (new);
}
*/