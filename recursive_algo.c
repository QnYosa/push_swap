/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 18:47:37 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	printf("sort_three_non_empty\n");

	tab = create_tab(x, sender);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	free(tab);
}

void	sort_four_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	
	printf("sort_four_non_empty\n");
	printf("yo x = %d\n", x);
	tab = create_tab(x, sender);
	int i;
	i = -1;
	// while (++i < x)
	// 	printf("tab[%d] = %d\n", i, tab[i]);
	// printf("STOOP\n");
	if (!tab)
		return ;
	// if (sender->head->number > sender->head->next->number)
	//  	swap(sender->head, sender->head, s);
	while (++i < x)
	{
		//printf("tab[i] = %d\n", sender->head->number);
		//printf("tab[%d] = %d\n", i, tab[i]);
		printf("i = %d\n", i);
		if (sender->head->number == tab[0])
		{
			printf("tab [0] = %d\n", tab[0]);
			push_first(sender, receiver);
			ra_list(receiver, s);
		}
		else if (sender->head->number == tab[1])
		{
			printf("tab [1] = %d\n", tab[1]);
			push_first(sender, receiver);
			ra_list(receiver, s);
		}
		else if (sender->head->number == tab[2])
		{
			printf("tab [2] = %d\n", tab[2]);			
			push_first(sender, receiver);
		}
		else if (sender->head->number == tab[3])
		{
			printf("tab [3] = %d\n", tab[3]);
			push_first(sender, receiver);
		}
		
		//one_list_display(sender);
	}
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	rra_list(receiver, s);
	rra_list(receiver, s);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, 'b');
	free(tab);
}

void	sort_five_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int i;
	printf("sort_five_non_empty\n");
// doutes sur le ra_list sur receiver
	tab = create_tab(x, sender);
	if (!tab)
		return ;
	i = -1;
	while (++i < x)
	{
		if (sender->head->number == tab[0])
		{
			printf("tab [0] = %d\n", tab[0]);
			ra_list(sender, s);
		}
		else if (sender->head->number == tab[1])
		{
			printf("tab [1] = %d\n", tab[1]);
			ra_list(sender, s);
		}
		else if (sender->head->number == tab[2])
		{
			printf("tab [2] = %d\n", tab[2]);
			push_first(sender, receiver);
			ra_list(receiver, r);
		}
		else if (sender->head->number == tab[3])
		{
			printf("tab [3] = %d\n", tab[3]);
			push_first(sender, receiver);
		}	
		else if (sender->head->number == tab[4])
		{
			printf("tab [4] = %d\n", tab[4]);	 
			push_first(sender, receiver);
		}
		//one_list_display(receiver);
	}
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	rra_list(receiver, r);
	rra_list(sender, s);
	rra_list(sender, s);
	if (sender->head->number < sender->head->next->number)
		swap(sender->head, sender->head->next, s);
	push_first(sender, receiver);
	push_first(sender, receiver);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, r);
	free(tab);
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, int x)
{
	printf("find_algo_rec, x = %d\n", x);
	if (x == 2)
	{
		if (stack_a->head->number < stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, 'b');
		push_first(stack_a, stack_b);
		push_first(stack_a, stack_b);
	}
	if (x == 3)
		sort_three_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 4)
		sort_four_non_empty(stack_b, stack_a, x, 'b', 'a');
	else if (x == 5)	
		sort_five_non_empty(stack_b, stack_a, x, 'b', 'a');
}