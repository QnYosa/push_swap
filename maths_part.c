/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 17:04:27 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	count_under_mid(t_list *sender, int mid)
{
	int	under;
	t_node	*iterator;

	under = 0;
	iterator = sender->head;
	while (iterator != NULL)
	{
		if (iterator->number <=  mid)
			under++;
		iterator = iterator->next;
	}
	return (under);
}

int	count_above_mid(t_list *sender, int mid)
{
	int	above;
	t_node	*iterator;

	above = 0;
	iterator = sender->head;
	while (iterator != NULL)
	{
		if (iterator->number >= mid)
			above++;
		iterator = iterator->next;
	}
	return (above);
}

void	un_ra_list(t_list *stack, int x, char c)
{
	int i;

	i = -1;
	while (++i < x)
	{
		rra_list(stack, c);
	}
}

int	push_bajo_mid(t_list *sender, t_list *receiver, int mid)
{
	int	i;
	int	k;
	int	under;

	under = count_under_mid(sender, mid);
	i = 0;
	k = 0;
	while (i < under)
	{
		if (sender->head->number <= mid)
		{
			push_first(sender, receiver);
			if (receiver->head->next != NULL)
			{
				if (receiver->head->number < receiver->head->next->number)
					swap(receiver->head, receiver->head->next, 'b');
			}
			i++;
		}
		else
		{
			ra_list(sender, 'a');
			k++;
		}
	}
	//list_display(sender, receiver);
	un_ra_list(sender, k, 'b');
	return (under);
}

int	push_above_mid_x(t_list *sender, t_list *receiver, int mid, int x)
{
	int	i;
	int	under;
	int above;

	i = -1;
	under = 0;
	above = 0;
	while (++i < x)
	{
		if (sender->head->number <= sender->head->next->number)
			swap(sender->head, sender->head->next, 'b');
		if (sender->head->number > mid)
		{
			push_first(sender, receiver);
			above++;
			if (receiver->head->next != NULL)
			{
				if (receiver->head->number > receiver->head->next->number)
					swap(receiver->head, receiver->head->next, 'b');
			}
		}
		else
		{
			ra_list(sender, 'a');
			under++;
		}
	}
	un_ra_list(sender, under, 'a');
	//list_display(receiver, sender);
	return (above);
}

int		find_mid(t_list *stack)
{
	int 				mid;
	int					*tab;
	t_node				*iterator;
	unsigned int		i;

	tab = malloc(sizeof(int) * stack->length);
	if (!tab)
		return (0);
	i = 0;
	iterator = stack->head;
	while (iterator != NULL)
	{
		tab[i] = iterator->number;
		i++;
		iterator = iterator->next;
	}
	ft_sort_int_tab(tab, stack->length);
	if (stack->length % 2 == 0)
		mid = tab[(stack->length / 2) - 1];
	else
		mid = tab[(stack->length / 2)];
	free(tab);
	return (mid);
}

int		find_mid_x(t_list *stack, int length)
{
	int 				mid;
	int					*tab;
	t_node				*iterator;
	int					i;

	tab = malloc(sizeof(int) * length);
	i = 0;
	iterator = stack->head;
	while (iterator != NULL && i < length)
	{
		tab[i] = iterator->number;
		i++;
		iterator = iterator->next;
	}
	ft_sort_int_tab(tab, length);
	if (stack->length % 2 == 0)
		mid = tab[(length / 2) - 1];
	else
		mid = tab[(length / 2)];
	free(tab);
	return (mid);
}
