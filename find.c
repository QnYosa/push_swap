/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:42:23 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:10:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

long	find_mid(t_list *stack)
{
	long					mid;
	long					*tab;
	t_node				*iterator;
	unsigned long		i;

	tab = malloc(sizeof(long) * stack->length);
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

long	find_mid_x(t_list *stack, long length)
{
	long					mid;
	long					*tab;
	t_node				*iterator;
	long					i;

	tab = malloc(sizeof(long) * length);
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

long	find_quarter(t_list *stack)
{
	long					mid;
	long					*tab;
	t_node				*iterator;
	unsigned long		i;

	tab = malloc(sizeof(long) * stack->length);
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
	if (stack->length % 4 == 0)
		mid = tab[(stack->length / 4) - 1];
	else
		mid = tab[(stack->length / 4)];
	free(tab);
	return (mid);
}
