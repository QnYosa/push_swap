/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_trio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:37:55 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/10 19:20:37 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

/*          POP AND PLACE            */


void	index_op(int n, t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	if (n == 0)
		up_to_do(podium->up, podium->tab, stack_a, stack_b);
	if (n == 1)
		middup_to_do(podium->mid_up, podium->tab, stack_a, stack_b);
	if (n == 2)
		midlow_to_go(podium->mid_down, podium->tab, stack_a, stack_b);
	if (n == 4)
		down_to_do(podium->down, podium->tab, stack_a, stack_b);
}

void	chose_operation(t_list *stack_a, t_list *stack_b, t_trio *podium)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i == 0)
			if (podium->up != 0)
				malloc_tab(podium->up, podium->tab);
		if (i == 1)
			if (podium->mid_up != 0)
				malloc_tab(podium->mid_up, podium->tab);
		if (i == 2)
			if (podium->mid_down != 0)
				malloc_tab(podium->mid_down, podium->tab);
		if (i == 3)
			if (podium->down != 0)
				malloc_tab(podium->down, podium->tab);
		tab_filler(i, podium, stack_a, stack_b);
		index_op(i, podium, stack_a, stack_b);
		free(podium->tab);
	}
}

void	malloc_tab(int n, int *tab)
{
	tab = malloc(sizeof(int) * n);
	if (!tab)
		return ;
}

int	chose_best_to_pop(t_list *stack_a, t_list *stack_b)
{
	t_trio	*podium;

	podium = NULL;
	init_podium_main(podium, stack_a, stack_b);
	chose_operation(stack_a, stack_b, podium);
	//free(tab);
	return (1);
}

/*
int	*init_tab(int *tab)
{
	tab = malloc(sizeof(int) * 3);
	if (!tab)
		return (NULL);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 2;
	return (tab);
}

void	count_moves_head(int *tab, t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head < stack_b->head)
		tab[0] += 0;
	else if (stack_a->head > stack_b->tail)
		tab[0] += 1;
	else if (stack_a->head > stack_b->head
		&& stack_a->head < stack_b->head->next)
		tab[0] += 1;
	else
		tab[0] = 0;
}

void	count_moves_(int *tab, t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head->next < stack_b->head)
		tab[1] += 0;
	else if (stack_a->head->next > stack_b->tail)
		tab[1] += 1;
	else if (stack_a->head->next > stack_b->head
		&& stack_a->head->next < stack_b->head->next)
		tab[1] += 1;
	else
		tab[1] = 0;
	if (stack_a->tail < stack_b->head)
		tab[2] += 0;
	else if (stack_a->tail > stack_b->tail)
		tab[2] += 1;
	else if (stack_a->tail > stack_b->head
		&& stack_a->tail < stack_b->head->next)
		tab[2] += 1;
	else
		tab[2] = 0;
}
void	init_podium(t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	
}
*/