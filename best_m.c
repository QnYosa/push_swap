/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:01:51 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/09 01:37:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	exec_best_move(t_move *best_move, t_list *a, t_list *b)
{
	while (best_move->move_in_both > 0)
	{
		if (best_move->rotate_r_in_a == TRUE \
		&& best_move->rotate_r_in_b ==  TRUE)
			rrr(a, b);
		else
			rr_91(a, b);
		best_move->move_in_both--;
	}
	while (best_move->move_in_a-- > 0)
	{
		if (best_move->rotate_r_in_a == TRUE)
			rra_list(a, a->c, a->l_co);
		else
			ra_list(a, a->c, a->l_co);
	}
	while (best_move->move_in_b-- > 0)
	{
		if (best_move->rotate_r_in_a == TRUE)
			rra_list(b, b->c, a->l_co);
		else
			ra_list(b, b->c, b->l_co);
	}
	push_first(a, b);
}