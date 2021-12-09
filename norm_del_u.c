/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_del_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:19:07 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/08 17:09:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	cond_del_u(t_commands **i, t_commands **del)
{
	*del = *i;
	(*del)->previous->next = (*del)->next;
	(*del)->next->previous = (*del)->previous;
	*i = (*del)->previous;
	free(*del);
	(*del) = (*del)->next;
	(*del)->previous->next = (*del)->next;
	(*del)->next->previous = (*del)->previous;
	free(*del);
	del = NULL;
}

void	cond_last(t_commands **i, t_commands **del)
{
	*del = *i;
	*i = (*i)->previous;
	(*i)->next = (*del)->next;
	(*del)->next->previous = *i;
	free(*del);
}

void	delete_useless(t_write **l)
{
	t_commands	*i;
	t_commands	*del;

	i = (*l)->head;
	del = NULL;
	if (!l || !(*l)->head->next)
		return ;
	while (i)
	{
		if (optimizer(&i, i->next))
		{
			del = i->next;
			i->next = del->next;
			del->next->previous = i;
			free(del);
		}
		if (delete_c(&i, &i->next))
			cond_del_u(&i, &del);
		if (rotate_b_killer(&i) || rotate_a_killer(&i) \
		|| rotate_ra_killer(&i) || rotate_rb_killer(&i))
		{
			cond_last(&i, &del);
		}
		i = i->next;
	}
}
