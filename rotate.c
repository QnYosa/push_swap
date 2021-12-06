/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:28:52 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:37:09 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	rotate_b_killer(t_commands **s1)
{
	t_commands	*i;
	t_commands	*del;

	i = (*s1);
	if (!compare((*s1)->command, "rb\n"))
		return (0);
	while (compare(i->command, "rb\n") && i->next)
		i = i->next;
	if (compare(i->command, "rrb\n") && i->next)
	{
		del = i;
		i = i->previous;
		i->next = del->next;
		del->next->previous = i;
		free(del);
		return (1);
	}
	return (0);
}

long	rotate_rb_killer(t_commands **s1)
{
	t_commands	*i;
	t_commands	*del;

	i = (*s1);
	if (!compare((*s1)->command, "rrb\n"))
		return (0);
	while (compare(i->command, "rrb\n") && i->next)
		i = i->next;
	if (compare(i->command, "rb\n") && i->next)
	{
		del = i;
		i = i->previous;
		i->next = del->next;
		del->next->previous = i;
		free(del);
		return (1);
	}
	return (0);
}

long	rotate_a_killer(t_commands **s1)
{
	t_commands	*i;
	t_commands	*del;

	i = (*s1);
	if (!compare((*s1)->command, "ra\n"))
		return (0);
	while (compare(i->command, "ra\n") && i)
		i = i->next;
	if (compare(i->command, "rra\n") && i)
	{
		del = i;
		i = i->previous;
		i->next = del->next;
		del->next->previous = i;
		free(del);
		return (1);
	}
	return (0);
}

long	rotate_ra_killer(t_commands **s1)
{
	t_commands	*i;
	t_commands	*del;

	i = (*s1);
	if (!compare((*s1)->command, "ra\n"))
		return (0);
	while (compare(i->command, "ra\n") && i->next)
		i = i->next;
	if (compare(i->command, "rra\n") && i->next)
	{
		del = i;
		i = i->previous;
		i->next = del->next;
		del->next->previous = i;
		free(del);
		return (1);
	}
	return (0);
}
