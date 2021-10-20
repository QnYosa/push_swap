/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:06:23 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/19 16:36:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus)
{
	int	i;

	i = -1;
	while (++i < n_argus->n_tabs)
		list_end(list, d_tab[i]);
}

void	add_index(t_list *list)
{
	t_node	*iterator;
	int		i;

	if (!list)
		return ;
	i = 0;
	iterator = list->head;
	while (iterator != NULL)
	{
		iterator->index = i;
		iterator = iterator->next;
		i++;
	}
}
