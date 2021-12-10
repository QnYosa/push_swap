/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:22:11 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 21:25:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_move	*init_move(void)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->rotate_r_in_a = FALSE;
	move->rotate_r_in_b = FALSE;
	move->move_in_a = 0;
	move->move_in_b = 0;
	move->move_in_both = 0;
	return (move);
}

void	move_in_a(t_move *move, int pos, t_list *a)
{
	int		len;

	len = pile_length(a);
	if (pos >= len / 2)
	{
		move->move_in_a = len - pos;
		move->rotate_r_in_a = TRUE;
	}
	else
	{
		move->move_in_a = pos;
		move->rotate_r_in_a = FALSE;
	}
	return ;
}

void	move_in_b(t_move *move, int nb, t_list *b)
{
	int		len;
	int		pos;

	len = pile_length(b);
	pos = find_place_in_pile_descending(nb, b);
	if (pos >= len / 2)
	{
		move->move_in_b = len - pos;
		move->rotate_r_in_b = TRUE;
	}
	else
	{
		move->move_in_b = pos;
		move->rotate_r_in_b = FALSE;
	}
	return ;
}