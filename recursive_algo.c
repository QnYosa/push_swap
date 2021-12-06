/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 23:47:46 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	init_touched(long *tab, long size)
{
	long	i;

	i = -1;
	while (++i < size)
		tab[i] = 0;
}

void	sort_three_non_empty(t_list *sender, t_list *receiver, char s, char r)
{
	//printf("%d, %d, %d\n", sender->head->number,sender->head->next->number, sender->head->next->next->number);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s, receiver->l_co);
	push_first(sender, receiver);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s, receiver->l_co);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r, receiver->l_co);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r, receiver->l_co);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, long x)
{
	long	*tab;
	long		i;
	long		*touched;

	touched = malloc(sizeof(long) * x);
	tab = create_tab(x, sender);
	i = -1;
	if (!tab)
		return ;
	//printf("%d, %d, %d, %d\n", tab[0], tab[1],tab[2],tab[3]);
	if (is_next(receiver, sender))
	{
		//printf("%d\n", sender->head->number);
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
		return ;
	}
	// ft_putnbr_fd(x, 1);
	// write(1, "\n", 1);
	if (tab[3] == sender->head->next->number)
	{
		// printf("%d\n", sender->head->number);
		// printf("%d, %d, %d, %d\n", tab[0], tab[1],tab[2],tab[3]);
		swap(sender->head, sender->head->next, sender->c, receiver->l_co);
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
		return ;
	}
	init_touched(touched, x);
	while (++i < x)
	{
		// if (receiver->head->number < -840 && receiver->head->number > -890)
		// 		list_display(receiver, sender);
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, receiver->c, receiver->l_co);
		if (sender->head->number == tab[0])
		{
			push_first(sender, receiver);
			ra_list(receiver, receiver->c, receiver->l_co);
			touched[0] = 1;
		}
		else if (sender->head->number == tab[1])
		{
			if (is_next(receiver, sender) && touched[3] == 1)
			{
				push_first(sender, receiver);
				if (touched[0] == 1)
					rra_list(receiver, receiver->c, receiver->l_co);
				else
					push_first(sender, receiver);
				free(tab);
				free(touched);
				return ;
			}
			else
			{
				push_first(sender, receiver);
				ra_list(receiver, receiver->c, receiver->l_co);
			}
		}
		else if (sender->head->number == tab[2])
		{
			push_first(sender, receiver);
			touched[2] = 1;
		}
		else if (sender->head->number == tab[3])
		{
			push_first(sender, receiver);
			touched[3] = 1;
		}	
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, \
			receiver->c, receiver->l_co);
	}
	if (receiver->length > 1)
		rra_list(receiver, receiver->c, receiver->l_co);
	if (receiver->length > 1)
		rra_list(receiver, receiver->c, receiver->l_co);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, receiver->c, receiver->l_co);
	// if (sender->head->number < -840 && receiver->head->number >= -890)
	// 	list_display(receiver, sender);
	free(tab);
	free(touched);
}

// void	sort_four_non_empty(t_list *sender, t_list *receiver, int x)
//
// {
// 	int	*tab;
// 	int	i;
// 	int	*touched;

// 	touched = malloc(sizeof(int) * x);
// 	tab = create_tab(x, sender);
// 	i = -1;
// 	if (!tab)
// 		return ;
// 	if (is_next(receiver, sender))
// 	{
// 		push_first(sender, receiver);
// 		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
// 		return ;
// 	}
// 	if (tab[3] == sender->head->next->number)
// 	{
// 		swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 		push_first(sender, receiver);
// 		sort_three_non_empty(sender, receiver, sender->c, receiver->c);
// 		return ;
// 	}
// 	if (tab[2] == sender->head->number)
// 	{
// 		push_first(sender, receiver);
// 		if (tab[3] == sender->head->next->number)
// 		{
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 			if (receiver->head->number > receiver->head->next->number)
// 				swap(receiver->head, receiver->head->next, \
//				receiver->c, receiver->l_co);
// 		}
// 		else
// 		{
// 			ra_list(sender, sender->c, receiver->l_co);
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 			rra_list(sender, sender->c, receiver->l_co);
// 			rra_list(sender, sender->c, receiver->l_co);
// 			push_first(sender, receiver);
// 		}
// 		if (sender->head->number < sender->head->next->number)
// 			swap(sender->head, sender->head->next, sender->c, receiver->l_co);
// 		push_first(sender, receiver);
// 		push_first(sender, receiver);
// 	}
// 	else if (tab[1] == sender->head->number)
// 	{
// 		if (tab[0] == sender->head->next->number)
// 		{
// 		}
// 	}
// 	free(tab);
// 	free(touched);
// }

void	find_algo_rec(t_list *stack_a, t_list *stack_b, long x)
{
	if (x == 2)
	{
		// printf("%d, %d\n", stack_a->head->number, stack_a->head->next->number);
		push_first(stack_b, stack_a);
		push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, stack_a->c, stack_a->l_co);
	}
	if (x == 3)
		sort_three_non_empty(stack_b, stack_a, stack_b->c, stack_a->c);
	else if (x == 4)
		sort_four_non_empty(stack_b, stack_a, x);
}
