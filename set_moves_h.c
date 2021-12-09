/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:20:46 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/09 18:18:56 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	set_move_in_both(t_move *move)
{
	if (move->rotate_r_in_a == move->rotate_r_in_b)
	{
		if (move->move_in_a < move->move_in_b)
		{
			move->move_in_both = move->move_in_a;
			move->move_in_b -= move->move_in_a;
			move->move_in_a = 0;
		}
		else if (move->move_in_b < move->move_in_a)
		{
			move->move_in_both = move->move_in_b;
			move->move_in_a -= move->move_in_b;
			move->move_in_b = 0;
		}
		else
		{
			move->move_in_both= move->move_in_a;
			move->move_in_a = 0;
			move->move_in_b = 0;
			move->move_in_b = 0;
		}
	}
	else
		move->move_in_both = 0;
	move->total_move = move->move_in_a + move->move_in_b + move->move_in_both;
}

void	copy_move_to_best_move(t_move *move, t_move *best_move)
{
	best_move->move_in_a = move->move_in_a;
	best_move->move_in_b = move->move_in_b;
	best_move->move_in_both = move->move_in_both;
	best_move->rotate_r_in_a = move->rotate_r_in_a;
	best_move->rotate_r_in_b = move->rotate_r_in_b;
	best_move->total_move = move->total_move;
}

t_move	*best_move_a_to_b(t_list *a, t_list *b)
{
	t_move	*move;
	t_move	*best_move;
	t_node	*i;
	int		pos;

	pos = 0;
	i = a->head;
	move = init_move();
	best_move = init_move();
	move_in_a(best_move, pos, a);
	move_in_b(best_move, i->number, b);
	set_move_in_both(best_move);
	while (i)
	{
		move_in_a(move, pos, a);
		move_in_b(move, i->number, b);
		set_move_in_both(move);
		if (best_move->total_move > move->total_move)
			copy_move_to_best_move(move, best_move);
		pos++;
		i = i->next;
	}
	free_move(move);
	return (best_move);
}
