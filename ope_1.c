/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/04 16:14:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	swap(t_node *first, t_node *second)
{
	int	tmp;

	if (!first || !second)
		return ;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
}

void	double_swap(t_list *list_1, t_list *list_2)
{
	swap(list_1->head, list_1->head->next);
	swap(list_2->head, list_2->head->next);
}
