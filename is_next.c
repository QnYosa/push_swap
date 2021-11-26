/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:58:54 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/26 19:23:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

int	is_next(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (stack_a->tab[i] != stack_a->head->number)
	{
		i++;
	}
	if (stack_a->tab[i + 1] == stack_b->head->number)
	{
		return (1);
	}
	return (0);
}

int	is_next_from(t_list *stack_a, int above)
{
	int		i;
	t_node	*tmp;

	tmp = stack_a->head;
	i = 0;
	while (i < above - 1)
	{
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (stack_a->tab[i] != tmp->number)
		i++;
	while (tmp && tmp->number == stack_a->tab[i])
	{
		i--;
		tmp = tmp->next;
	}
	if (tmp)
		return (0);
	return (1);
}

int	*do_tab(int size, t_list *stack)
{
	int		i;
	int		*tab;
	t_node	*node;

	tab = malloc(sizeof(int) * size);
	node = stack->head;
	i = -1;
	while (++i < size && node)
	{
		tab[i] = node->number;
		node = node->next;
	}
	return (tab);
}

int	*correct_touched(int *touched, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (touched[i + 1] == 0 && touched[i] == 1)
			touched[i] = 0;
	}
	return (touched);
}

int	*is_next_top_a(int *tab, int *touched, int size, t_list *stack_a)
{
	int		i;
	int		*order;
	t_node	*tmp;

	tmp = stack_a->head;
	order = do_tab(size, stack_a);
	if (!order)
		return (0);
	i = size - 1;
	while (i >= 0)
	{
		if (tab[i] == order[i])
			touched[i] = 1;
		else
			touched[i] = 0;
		i--;
	}
	touched = correct_touched(touched, size);
	free(order);
	return (touched);
}
