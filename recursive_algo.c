/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:15:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 23:23:15 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;

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
	int i;
	int	*touched;

	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	i = -1;
	if (!tab)
		return ;
	//printf("HOLA\n");
	if (is_next(receiver, sender))
	{
		//list_display(receiver, sender);
		push_first(sender, receiver);
		sort_three_non_empty(sender, receiver, x - 1, s, r);
		//list_display(receiver, sender);
		return ;
	}
	while (++i < x)
	{
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r);
		if (sender->head->number == tab[0])
		{
			push_first(sender, receiver);
			ra_list(receiver, s);
			touched[0] = 1;
		}
		else if (sender->head->number == tab[1])
		{
			if (is_next(receiver, sender) && touched[3] == 1)
			{
				//printf(" sort four non empty 1 %d\n", receiver->head->number);
				push_first(sender, receiver);
			 	if (touched[0] == 1)
			 		rra_list(receiver, receiver->c);
				else
					push_first(sender, receiver);
			 	return ;
			}
			else
			{
				push_first(sender, receiver);
				ra_list(receiver, s);
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
			swap(receiver->head, receiver->head->next, r);
		//list_display(receiver, sender);
	}
	rra_list(receiver, s);
	rra_list(receiver, s);
	if (receiver->head->number > receiver->head->next->number)
		swap(receiver->head, receiver->head->next, receiver->c);
	free(tab);
	free(touched);
	//list_display(receiver, sender);
}

void	sort_five_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int i;
	int	*touched;
	int rad;

	rad = 0;
	tab = create_tab(x, sender);
	touched = malloc(sizeof(int) * x);
	if (!tab || !touched)
		return ;
	i = -1;
	if (is_next(receiver, sender))
	{
		//list_display(receiver, sender);
		push_first(sender, receiver);
		sort_four_non_empty(sender, receiver, x - 1, s, r);
		//list_display(receiver, sender);
		return ;
	}
	else
	{
		while (++i < x)
		{
			// if (receiver->head->number > receiver->head->next->number)
			// 	swap(receiver->head, receiver->head->next, receiver->c);
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s);
				rad++;
			}
			else if (sender->head->number == tab[1])
			{
				ra_list(sender, s);	
				rad++;
			}
			else if (sender->head->number == tab[2])
			{
				if (is_next(receiver, sender) && touched[4] == 1)
				{
					touched[2] = 1;
					push_first(sender, receiver);
					un_ra_list(sender, rad, sender->c);
					push_first(sender, receiver);
					push_first(sender, receiver);
					if (receiver->head->number > receiver->head->next->number)
						swap(receiver->head, receiver->head->next, r);
					return ; 
				}
				else
				{
					push_first(sender, receiver);
					ra_list(receiver, r);
				}
			}
			else if (sender->head->number == tab[3])
			{
				touched[3] = 1;
				push_first(sender, receiver);
			}
			else if (sender->head->number == tab[4])
			{
				push_first(sender, receiver);
				touched[4] = 1;
			}
		}
		if (receiver->head->number > receiver->head->next->number)
			swap(receiver->head, receiver->head->next, receiver->c);
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
		free(touched);
		}
}

void	find_algo_rec(t_list *stack_a, t_list *stack_b, int x)
{
	if (x == 2)
	{
		if (stack_a->head->number < stack_a->head->next->number)
			swap(stack_a->head, stack_a->head->next, stack_a->c);
		push_first(stack_a, stack_b);
		push_first(stack_a, stack_b);
	}
	if (x == 3)
	{
		//ft_putstr_fd("sort three non empty\n", 1);
		//list_display(stack_a, stack_b);
		sort_three_non_empty(stack_b, stack_a, x, stack_b->c, stack_a->c);
		//list_display(stack_a, stack_b);
		
	}
	else if (x == 4)
	{
		//ft_putstr_fd("sort four non empty\n", 1);
		//list_display(stack_a, stack_b);
		sort_four_non_empty(stack_b, stack_a, x, stack_b->c, stack_a->c);
		//list_display(stack_a, stack_b);
	}
	else if (x == 5)	
	{
		//ft_putstr_fd("sort five non empty\n", 1);
		//list_display(stack_a, stack_b);
		sort_five_non_empty(stack_b, stack_a, x, stack_b->c, stack_a->c);
		//list_display(stack_a, stack_b);
	}
}
