/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:18:32 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/05 22:57:53 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	*list_insert_norm(t_node *tmp, t_list *list, char *content)
{
	if (tmp->next == NULL)
		list = list_end(list, content);
	else if (tmp->previous == NULL)
		list = list_start(list, content);
	return (list);
}

t_node	*malloc_node_norm(t_node *tmp, t_node *new, t_list *list, char *content)
{
	new = (t_node *)malloc(sizeof(t_node *));
	if (!new)
		return (NULL);
	new = new_node(new, tmp, content, list);
	return (new);
}
