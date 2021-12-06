/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:37:39 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:40:09 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

long	delete_c(t_commands **s1, t_commands**s2)
{
	if (!*s1 || !*s2)
		return (0);
	if (compare((*s1)->command, "sa\n") == 1 \
		&& compare((*s2)->command, "sa\n") == 1)
		return (1);
	else if (compare((*s1)->command, "sb\n") == 1 \
		&& compare((*s2)->command, "sb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rb\n") == 1 \
		&& compare((*s2)->command, "rrb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rrb\n") == 1 \
		&& compare((*s2)->command, "rb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "ra\n") == 1 \
		&& compare((*s2)->command, "rra\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rra\n") == 1 \
		&& compare((*s2)->command, "ra\n") == 1)
		return (1);
	return (0);
}
