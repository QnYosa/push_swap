/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:02:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/09 19:03:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

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

	len = (int)a->length;
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
