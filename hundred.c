/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:02:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 23:05:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	pile_length(t_list *stack)
{
	t_node	*current;
	int			i;

	i = 0;
	if (stack->head == NULL)
		return (0);
	current = stack->head;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	optimizer_push(t_list *a, t_list *b)
{
	int		pos;

	pos = 0;
	while ((int)a->length > 2)
	{
		pos = find_smallest_nb_pos(a);
		if (pos == 0)
			push_first(a, b);
		else if (pos >= (int)a->length / 2)
			rra_list(a, a->c, a->l_co);
		else if (pos < (int)a->length / 2)
			ra_list(a, a->c, a->l_co);
	}
	return ;
}

void	sort_all(t_list *a, t_list *b)
{
	int		optimizer;
	t_move	*best_move;

	optimizer = 2;
	push_first(a, b);
	push_first(a, b);
	while ((int)a->length > optimizer)
	{
		best_move = best_move_a_to_b(a, b);
		exec_best_move(best_move, a, b);
		free_move(best_move);
	}
	optimizer_push(a, b);
	push_back_in_a(a, b);
}

void	sort_pile(t_list *a)
{
	t_list	*b;
	int		len;

	len = pile_length(a);
	b = NULL;
	b = init_list();
	a->c = 'a';
	b->c = 'b';
	sort_all(a, b);
	return ;
}

void	hundred_arg(t_list *a)
{
	sort_pile(a);
}

/*

void	optimizer_push(t_list *a, t_list *b)
{
	int		pos;

	pos = 0;
	while (pile_length(a) > 2)
	{
		pos = find_smallest_nb_pos(a);
		if (pos == 0)
			g_push_first(a, b);
		else if (pos >= pile_length(a) / 2)
			g_rra_list(a, a->c);
		else if (pos < pile_length(a) / 2)
			g_ra_list(a, a->c);
	}
	return ;
}

void	sort_all(t_list *a, t_list *b)//sort.c
{
	int		optimizer;
	t_move	*best_move;

	optimizer = 2;
	g_push_first(a, b);
	g_push_first(a, b);
	while (pile_length(a) > optimizer)
	{
		//list_display(a, b);
		best_move = best_move_a_to_b(a, b);
		exec_best_move(best_move, a, b);//exec_cmd.c
		free_move(best_move);
	}
	optimizer_push(a, b);
	push_back_in_a(a, b);
	//list_display(a, b);
}
*/