/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_pop_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:36:14 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/20 23:31:16 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	up_to_do(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = -1;
	while (++i < sizeof(tab) / sizeof(int))
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

void	tab_filler(int n, int *tab, t_list *stack_a, t_list *stack_b)
{
	if (!tab)
		return ;
	if (n == 0)
		up_fill(tab, stack_a, stack_b);
	else if (n == 1)
		midup_fill(tab, stack_a, stack_b);
	else if (n == 2)
		midlow_fill(tab, stack_a, stack_b);
	else if (n == 3)
		down_fill(tab, stack_a, stack_b);
	ft_sort_int_tab(tab, (sizeof(tab) / sizeof(int)));
	if (i == 1 || i == 2)
		ft_rev_int_tab(tab, (sizeof(tab) / sizeof(int)));
	if (n == 0)
		up_to_do(n, tab, stack_a, stack_b);
	else if (n == 1)
		midup_fill(tab, stack_a, stack_b);
	else if (n == 2)
		midlow_fill(tab, stack_a, stack_b);
	else if (n == 3)
		down_fill(tab, stack_a, stack_b);
	//chercher la valeur qui est egale 
	//faire op qui lui revient. 
}
