/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:06:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/09 18:52:15 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	rotate_n_times(t_list *a, t_list *b, int pos)
{
	int		len;

	b->length--;
	b->length++;
	len = a->length;
	if (pos <= len / 2)
	{
		while (pos != 0)
		{
			ra_list(a, a->c, a->l_co);
			pos--;
		}
	}
	else if (pos > len / 2)
	{
		while (pos != len)
		{
			rra_list(a, a->c, a->l_co);
			pos++;
		}
	}
	return ;
}

int	find_biggest_nb_pos(t_list *stack)
{
	t_node		*current;
	int			i;
	int			pos;
	int			nb;

	current = stack->head;
	nb = current->number;
	i = 0;
	pos = 0;
	current = current->next;
	while (current)
	{
		i++;
		if (current->number > nb)
		{
			nb = current->number;
			pos = i;
		}
		current = current->next;
	}
	return (pos);
}

int	find_smallest_nb_pos(t_list *stack)
{
	t_node		*current;
	int			i;
	int			pos;
	int			nb;

	current = stack->head;
	nb = current->number;
	i = 0;
	pos = 0;
	current = current->next;
	while (current)
	{
		i++;
		if (current->number < nb)
		{
			nb = current->number;
			pos = i;
		}
		current = current->next;
	}
	return (pos);
}

int	find_min_nb(t_list *st)
{
	long	nb;
	t_node	*i;
	
	i = st->head;
	nb = i->number;	
	while (i)
	{
		if (i->number < nb)
			nb = i->number;
		i = i->next;
	}
	return (nb);
}

int	find_max_nb(t_list *st)
{
	long			nb;
	t_node			*i;

	i = st->head;
	nb = i->number;
	while (i)
	{
		if (i->number > nb)
			nb = i->number;
		i = i->next;
	}
	return (nb);
}