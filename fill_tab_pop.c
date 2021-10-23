/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:31:51 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/23 18:28:09 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	up_fill(int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->head->number < stack_b->head->number)
		tab[i++] = stack_a->head->number;
	if (stack_a->head->next->number < stack_b->head->number)
		tab[i++] = stack_a->head->next->number;
	if (stack_a->tail->number < stack_b->head->number)
		tab[i] = stack_a->tail->number;
}

void	midup_fill(int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->head->number > stack_b->head->number
		&& stack_a->head->number < stack_b->head->next->number)
		tab[i++] = stack_a->head->number;
	if (stack_a->head->next->number > stack_b->head->number
		&& stack_a->head->next->number < stack_b->head->next->number)
		tab[i++] = stack_a->head->next->number;
	if (stack_a->tail->number > stack_b->head->number
		&& stack_a->tail->number < stack_b->head->next->number)
		tab[i] = stack_a->tail->number;
}

void	midlow_fill(int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->head->number < stack_b->tail->number
		&& stack_a->head->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		tab[i++] = stack_a->head->number;
	if (stack_a->head->next->number < stack_b->tail->number
		&& stack_a->head->next->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		tab[i++] = stack_a->head->next->number;
	if (stack_a->tail->number < stack_b->tail->number
		&& stack_a->tail->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		tab[i++] = stack_a->tail->number;
}

void	down_fill(int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->head->number > stack_b->tail->number)
		tab[i++] = stack_a->head->number;
	if (stack_a->head->next->number > stack_b->tail->number)
		tab[i++] = stack_a->head->next->number;
	if (stack_a->tail->number > stack_b->tail->number)
		tab[i] = stack_a->tail->number;
}
