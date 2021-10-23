/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_fill_podium.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:17:30 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/23 18:47:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	set_to_zero(t_trio *podium)
{
	podium = malloc(sizeof(t_trio));
	if (!podium)
		exit(3);
	podium->up = 0;
	podium->mid_up = 0;
	podium->mid_down = 0;
	podium->down = 0;
	podium->tab = NULL;
}

void	up_down(t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head->number < stack_b->head->number)
		podium->up += 1;
	else if (stack_a->head->number > stack_b->tail->number)
		podium->down += 1;
	if (stack_a->head->next->number < stack_b->head->number)
		podium->up += 1;
	else if (stack_a->head->next->number > stack_b->tail->number)
		podium->down += 1;
	if (stack_a->tail->number < stack_b->head->number)
		podium->up += 1;
	else if (stack_a->tail->number > stack_b->tail->number)
		podium->down += 1;
}

void	middle_up_down(t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head->number > stack_b->head->number
		&& stack_a->head->number < stack_b->head->next->number)
		podium->mid_up += 1;
	else if (stack_a->head->number < stack_b->tail->number
		&& stack_a->head->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		podium->mid_down += 1;
	if (stack_a->head->next->number > stack_b->head->number
		&& stack_a->head->next->number < stack_b->head->next->number)
		podium->mid_up += 1;
	else if (stack_a->head->next->number < stack_b->tail->number
		&& stack_a->head->next->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		podium->mid_down += 1;
	if (stack_a->tail->number > stack_b->head->number
		&& stack_a->tail->number < stack_b->head->next->number)
		podium->mid_up += 1;
	else if (stack_a->tail->number < stack_b->tail->number
		&& stack_a->tail->number > stack_b->tail->previous->number
		&& stack_b->length >= 3)
		podium->mid_down += 1;
}

void	init_podium_main(t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	set_to_zero(podium);
	up_down(podium, stack_a, stack_b);
	middle_up_down(podium, stack_a, stack_b);
}
