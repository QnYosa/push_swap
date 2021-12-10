/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:29:26 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 22:28:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"
//sort_utils_2.c

int	find_place_in_pile_descending(int nb, t_list *stack)
{
	t_node		*current;
	int			pos;
	int			previous_nb;

	pos = 0;
	current = stack->head;
	if (nb > find_max_nb(stack))//sort_utils.c
		return (find_biggest_nb_pos(stack));//sort_utils.c
	if (nb < find_min_nb(stack))//sort_utils.c
		return (find_smallest_nb_pos(stack) + 1);//sort_utils.c
	previous_nb = stack->head->number;
	while (current)
	{
		if (previous_nb > nb && nb > current->number)
			return (pos);
		previous_nb = current->number;
		current = current->next;
		pos++;
	}
	return (0);
}

long	find_place_in_pile_ascending(int nb, t_list *stack)
{
	t_node		*current;
	long		pos;
	long		previous_nb;

	pos = 0;
	current = stack->head;
	if (nb > find_max_nb(stack))
		return (find_biggest_nb_pos(stack) + 1);
	if (nb < find_min_nb(stack))
		return (find_smallest_nb_pos(stack));
	previous_nb = stack->head->number;
	while (current)
	{
		if (previous_nb < nb && nb < current->number)
			return (pos);
		previous_nb = current->number;
		current = current->next;
		pos++;
	}
	return (0);
}

void	final_rotate(t_list *a)
{
	long		pos;
	long		move;

	move = 0;
	pos = find_smallest_nb_pos(a);
	if (pos >= pile_length(a) / 2)
		move = pile_length(a) - pos;
	else if (pos < pile_length(a) / 2)
		move = pos;
	while (move > 0)
	{
		if (pos >= pile_length(a) / 2)
			g_rra_list(a, a->c);
		else if (pos < pile_length(a) / 2)
			g_ra_list(a, a->c);
		move--;
	}
	return ;
}

void	push_back_in_a(t_list *a, t_list *b)
{//sort_utils_2.c
	long		pos;
	long		move;

	while (pile_length(b) > 0)
	{
		pos = find_place_in_pile_ascending(b->head->number, a);
		if (pos >= pile_length(a) / 2)
			move = pile_length(a) - pos;
		else if (pos < pile_length(a) / 2)
			move = pos;
		while (move > 0)
		{
			if (pos >= pile_length(a) / 2)
				g_rra_list(a, a->c);
			else if (pos < pile_length(a) / 2)
				g_ra_list(a, a->c);
			move--;
		}
		g_push_first(b, a);
	}
	final_rotate(a);
	return ;
}
