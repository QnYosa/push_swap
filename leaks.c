/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:37:33 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/05 22:56:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	delete_list(t_list **list)
{
	t_node				*tmp;
	t_node				*del;
	unsigned int		i;

	i = 0;
	if (*list == NULL)
		return ;
	tmp = (*list)->head;
	while (tmp != NULL && i <= (*list)->length)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(*list), *list = NULL;
}
