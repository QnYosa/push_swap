/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:19 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/02 17:40:33 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	count_under_mid(t_list *sender, int mid)
{
	int		under;
	t_node	*iterator;

	under = 0;
	iterator = sender->head;
	while (iterator != NULL)
	{
		if (iterator->number <= mid)
			under++;
		iterator = iterator->next;
	}
	return (under);
}

void	un_ra_list(t_list *stack, int x, char c, t_write *l)
{
	int	i;

	i = -1;
	while (++i < x && stack->length > 1)
		rra_list(stack, c, l);
}

int	push_bajo_mid(t_list *sender, t_list *receiver, int mid)
{
	int	i;
	int	k;
	int	under;
	int	pushed;

	under = count_under_mid(sender, mid);
	i = 0;
	k = 0;
	pushed = 0;
	while (i < under && pushed <= under)
	{
		if (sender->head->number <= mid)
		{
			push_first(sender, receiver);
			if (receiver->head->number <= sender->quarter && sender->first_mid == 0 && receiver->head->next != NULL)
				ra_list(receiver, receiver->c, sender->l_co);
			pushed++;
			i++;
		}
		else
		{
			ra_list(sender, sender->c, sender->l_co);
			k++;
		}
	}
	if (sender->first_mid == 1)
		un_ra_list(sender, k, sender->c, sender->l_co);
	if (sender->first_mid == 0)
		sender->first_mid = 1;
	return (under);
}

int	find_mid(t_list *stack)
{
	int					mid;
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

int	find_mid_x(t_list *stack, int length)
{
	int					mid;
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

int	find_quarter(t_list *stack)
{
	int					mid;
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
	if (stack->length % 4 == 0)
		mid = tab[(stack->length / 4) - 1];
	else
		mid = tab[(stack->length / 4)];
	free(tab);
	return (mid);
}
