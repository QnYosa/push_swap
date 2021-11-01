/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/01 18:58:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_mediane_nodes	*fill_med_nodes(int mid, t_list *stack)
{
	t_mediane_nodes	*new;
	new = (t_node *)malloc(sizeof(t_mediane_nodes));
	if (!new)
		return (NULL);
	new->mediane = mid;
	new->length = stack->length;
	tmp->next->previous = new;
	tmp->previous->next = new;
	new->previous = tmp->previous;
	new->next = tmp;
	list->length++;
	return (new);
}
