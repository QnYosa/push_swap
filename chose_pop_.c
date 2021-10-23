/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_pop_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:36:14 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/23 18:23:34 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

/* 						ON FAIT LES OPERATIONS  */
void	up_to_do(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (tab[i] == stack_a->head->number)
			push_first(stack_a, stack_b);
		else if (tab[i] == stack_a->head->next->number)
		{
			swap_a(stack_a->head, stack_a->head->next);
			push_first(stack_a, stack_b);
		}
		else if (tab[i] == stack_a->tail->number)
		{
			rra_list(stack_a);
			push_first(stack_a, stack_b);
		}
	}
}

void	down_to_do(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (tab[i] == stack_a->head->number)
		{
			push_first(stack_a, stack_b);
			ra_list(stack_b);
		}
		else if (tab[i] == stack_a->head->next->number)
		{
			if (stack_a->head->previous != NULL)
				swap_a(stack_a->head, stack_a->head->next);
			push_first(stack_a, stack_b);
			ra_list(stack_b);
		}
		else if (tab[i] == stack_a->tail->number)
		{
			rra_list(stack_a);
			push_first(stack_a, stack_b);
			ra_list(stack_b);
		}
	}
}

void	middup_to_do(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	headless;

	i = -1;
	headless = 0;
	while (++i < n)
	{
		if (tab[i] == stack_a->head->number)
		{
			push_first(stack_a, stack_b);
			swap_b(stack_b->head, stack_b->head->next);
			headless += 1;
		}
		else if (tab[i] == stack_a->head->next->number)
		{
			if (headless == 0)
				swap_a(stack_a->head, stack_a->head->next);
			push_first(stack_a, stack_b);
			swap_b(stack_b->head, stack_b->head->next);
		}
		else if (tab[i] == stack_a->tail->number)
		{
			rra_list(stack_a);
			push_first(stack_a, stack_b);
			swap_b(stack_b->head, stack_b->head->next);
		}
	}
}

void	midlow_to_go(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	headless;

	headless = 0;
	i = -1;
	while (++i < n)
	{
		if (tab[i] == stack_a->head->number)
		{
			push_first(stack_a, stack_b);
			rra_list(stack_b);
			swap_b(stack_b->head, stack_b->head->next);
			ra_list(stack_b);
			ra_list(stack_b);
			headless += 1;
		}
		else if (tab[i] == stack_a->head->next->number)
		{
			if (headless == 0)
				swap_a(stack_a->head, stack_a->head->next);
			push_first(stack_a, stack_b);
			rra_list(stack_b);
			swap_b(stack_b->head, stack_b->head->next);
			ra_list(stack_b);
			ra_list(stack_b);
		}
		else if (tab[i] == stack_a->tail->number)
		{
			rra_list(stack_a);
			push_first(stack_a, stack_b);
			rra_list(stack_b);
			swap_b(stack_b->head, stack_b->head->next);
			ra_list(stack_b);
			ra_list(stack_b);
		}
	}
}

int	which_size(int index, t_trio *podium)
{
	int	i;

	i = 0;
	if (index == 0)
		i = podium->up;
	if (index == 1)
		i = podium->mid_up;
	if (index == 2)
		i = podium->mid_down;
	if (index == 3)
		i = podium->down;
	return (i);
}

void	tab_filler(int n, t_trio *podium, t_list *stack_a, t_list *stack_b)
{
	if (!podium->tab)
		return ;
	if (n == 0)
		up_fill(podium->tab, stack_a, stack_b);
	else if (n == 1)
		midup_fill(podium->tab, stack_a, stack_b);
	else if (n == 2)
		midlow_fill(podium->tab, stack_a, stack_b);
	else if (n == 3)
		down_fill(podium->tab, stack_a, stack_b);
	ft_sort_int_tab(podium->tab, which_size(n, podium));
	if (n == 1 || n == 2)
		ft_rev_int_tab(podium->tab, which_size(n, podium));
	if (n == 0)
		up_to_do(n, podium->tab, stack_a, stack_b);
	else if (n == 1)
		midup_fill(podium->tab, stack_a, stack_b);
	else if (n == 2)
		midlow_fill(podium->tab, stack_a, stack_b);
	else if (n == 3)
		down_fill(podium->tab, stack_a, stack_b);
	//chercher la valeur qui est egale 
	//faire op qui lui revient. 
}
