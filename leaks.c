/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:37:33 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/04 17:30:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	delete_list(t_list **list)
{
	t_node	*tmp;
	t_node	*del;

	if (list == NULL)
		return ;
	tmp = list->head;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(*list);
	list = NULL;
}
