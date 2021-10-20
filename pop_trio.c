/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_trio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:37:55 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/20 22:02:50 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

/*          POP AND PLACE            */

void	chose_operation(int *tab, t_list *stack_a, t_list *stack_b, \
t_trio *podium)
{
	int	*tab;
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i == 0)
		{
			malloc_tab(podium->up, tab);
			tab_filler(tab);
		}
		if (i == 1)
			malloc_tab(podium->mid_up, tab);
		if (i == 2)
			malloc_tab(podium->md_down, tab);
		if (i == 3)
			malloc_tab(podium->down, tab);
	}
	free(tab);
}

int	chose_best_to_pop(t_list *stack_a, t_list *stack_b)
{
	int		*tab;
	t_trio	*podium;

	init_podium_main(podium, stack_a, stack_b);
	translate_podium()
	tab = init_tab(tab);
	count_moves_head(tab, stack_a, stack_b);
	count_moves(tab, stack_a, stack_b);
	free(tab);
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