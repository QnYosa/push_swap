/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:02:29 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:39:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

long	opt_4(t_commands **s1, t_commands *s2)
{
	if (compare((*s1)->command, "rra\n") == 1 \
	&& compare(s2->command, "rrb\n") == 1)
	{
		(*s1)->command = "rrr\n";
		return (1);
	}
	else if (compare((*s1)->command, "rrb\n") == 1 \
	&& compare(s2->command, "rra\n") == 1)
	{
		(*s1)->command = "rrr\n";
		return (1);
	}
	return (0);
}

long	opt_3(t_commands **s1, t_commands *s2)
{
	if (compare((*s1)->command, "rrr\n") == 1 && compare(s2->command, "rra\n"))
	{
		(*s1)->command = "rrb\n";
		return (1);
	}
	else if (compare((*s1)->command, "rr\n") == 1 \
	&& compare(s2->command, "rra\n"))
	{
		(*s1)->command = "rb\n";
		return (1);
	}
	else if (compare((*s1)->command, "rr\n") == 1 \
	&& compare(s2->command, "rrb\n"))
	{
		(*s1)->command = "ra\n";
		return (1);
	}
	else if (compare((*s1)->command, "sa\n") == 1 \
	&& compare(s2->command, "sb\n"))
	{
		(*s1)->command = "ss\n";
		return (1);
	}
	return (0);
}

long	opt_2(t_commands **s1, t_commands *s2)
{
	if (compare((*s1)->command, "sb\n") == 1 && compare(s2->command, "sa\n"))
	{
		(*s1)->command = "ss\n";
		return (1);
	}
	else if (compare((*s1)->command, "ss\n") == 1 \
	&& compare(s2->command, "sa\n"))
	{
		(*s1)->command = "sb\n";
		return (1);
	}
	else if (compare((*s1)->command, "ss\n") == 1 \
	&& compare(s2->command, "sb\n"))
	{
		(*s1)->command = "sa\n";
		return (1);
	}
	else if (compare((*s1)->command, "rrr\n") == 1 \
	&& compare(s2->command, "rrb\n"))
	{
		(*s1)->command = "rra\n";
		return (1);
	}
	return (0);
}

long	optimizer(t_commands **s1, t_commands *s2)
{
	if (!*s1 || !s2)
		return (0);
	if (compare((*s1)->command, "ra\n") == 1 \
	&& compare(s2->command, "rb\n") == 1)
	{
		(*s1)->command = "rr\n";
		return (1);
	}
	else if (compare((*s1)->command, "rb\n") == 1 \
	&& compare(s2->command, "ra\n") == 1)
	{
		(*s1)->command = "rr\n";
		return (1);
	}
	if (!opt_2(s1, s2) || !opt_3(s1, s2) \
	|| !opt_4(s1, s2))
		return (0);
	return (0);
}
