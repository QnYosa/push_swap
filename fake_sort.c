/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:03:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 19:05:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_tab(t_list *list)
{
	int		i;
	t_node	*iterator;
	t_node	*value;
	int		*tab;
	
	tab = (int *)malloc(sizeof(int) * list->length);
	i = 0;
	while (value != NULL)
	{
		iterator = list->head;
		while (iterator != NULL)
		{
			tab[i] = iterator->number;
		}
	}
}
