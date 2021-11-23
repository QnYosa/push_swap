/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_non_empty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:01:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/23 22:50:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	sort_three_top_non_empty(t_list *stack, int x)
{
	int *tab;

	tab = create_tab(x, stack);
	if (stack->head->number == tab[0] && stack->head->next->number == tab[1] && stack->head->next->next->number == tab[2])
		return ;
	else if (stack->head->number == tab[0] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[1])
	{
		//printf("yo 2\n");
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
	}
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[2])
	{
		//printf("yo 3\n");
		swap(stack->head, stack->head->next, 'a');
	}
	else if (stack->head->number == tab[1] && stack->head->next->number == tab[2] && stack->head->next->next->number == tab[0])
	{
		//printf("yo 4\n");
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[0] && stack->head->next->next->number == tab[1])
	{
		//printf("yo 5\n");
		swap(stack->head, stack->head->next, 'a');
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');		
	}
	else if (stack->head->number == tab[2] && stack->head->next->number == tab[1] && stack->head->next->next->number == tab[0])
	{
		//printf("yo 6\n");
		swap(stack->head, stack->head->next, 'a');
		ra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');
		rra_list(stack, 'a');
		swap(stack->head, stack->head->next, 'a');		
	}
	free(tab);
}

void	sort_four_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int *touched;
	int i;
	int ra;
	(void)r;

	ra = 0;
	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	if (!touched || !tab)
		return ;
	i = -1;
	touched = is_next_top_a(tab, touched, x, sender);
	/*ft_putstr_fd("four tab[4]_", 1);
	ft_putnbr_fd(tab[2], 1);
	ft_putstr_fd("\n", 1);*/
	if (touched[3] == 1)
	{
		//list_display(sender, receiver);
		//ft_putstr_fd("go algo de trois\n", 1);
		//ft_putnbr_fd(sender->head->number, 1);
		//ft_putstr_fd("\n", 1);
		sort_three_top_non_empty(sender, x - 1);
		free(touched);
		return ;
	}
	else
	{
		//ft_putstr_fd("YO Je PASSe par la\n", 1);
		while (++i < x)
		{
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s);
				ra++;
			}
			if (sender->head->number == tab[1])
			{
				ra_list(sender, s);
				ra++;
			}
			if (sender->head->number == tab[2])
			{
				if (receiver->head->number != tab[3] && ra != 2)
					push_first(sender, receiver);
				else
					swap(sender->head, sender->head->next, sender->c);
			}
			if (sender->head->number == tab[3])
			{
				if (receiver->head->number != tab[2] && ra != 2)
					push_first(sender, receiver);
				else
					swap(sender->head, sender->head->next, sender->c);
			}
		}
	}
	if (sender->head->number > sender->head->next->number)
	 	swap(sender->head, sender->head->next, r);
	// printf("touched[1] = %d\n", touched[1]);
	// printf("touched[2] = %d\n", touched[2]);
	// printf("touched[3] = %d\n", touched[3]);
	if (sender->head->number > sender->head->next->number)
	 	swap(sender->head, sender->head->next, s);
	if (receiver->head->number == tab[3] || receiver->head->number == tab[2])
		push_first(receiver, sender);
	if (receiver->head->number == tab[3] || receiver->head->number == tab[2])
		push_first(receiver, sender);
	if (sender->head->number > sender->head->next->number)
	 	swap(sender->head, sender->head->next, s);
	//rra_list(sender, sender->c);
	//rra_list(sender, sender->c);
	un_ra_list(sender, ra, sender->c);
	if (sender->head->number > sender->head->next->number)
	 	swap(sender->head, sender->head->next, s);
	free(tab);
}

void	sort_five_top_non_empty(t_list *sender, t_list *receiver, int x, char s, char r)
{
	int *tab;
	int i;
	int *touched;
	int ra;

	ra = 0;
	touched = malloc(sizeof(int) * x);
	tab = create_tab(x, sender);
	if (!tab || !touched)
		return ;
	i = -1;
	touched = is_next_top_a(tab, touched, x, sender);
	//list_display(sender, receiver);
	if (touched[4] == 1)
	{
		/*
		ft_putstr_fd("five tab[4]_", 1);
		ft_putnbr_fd(tab[4], 1);
		ft_putstr_fd("\n", 1);*/
		sort_four_top_non_empty(sender, receiver, x, s, r);
		return ;
	}
	else
	{
		while (++i < x)
		{
			if (sender->head->number == tab[0])
			{
				ra_list(sender, s);
			}
			else if (sender->head->number == tab[1])
				ra_list(sender, s);
			else if (sender->head->number == tab[2])
			{
				push_first(sender, receiver);
				ra_list(receiver, r);
			}
			else if (sender->head->number == tab[3])
				push_first(sender, receiver);
			else if (sender->head->number == tab[4])
				push_first(sender, receiver);
		}
		if (receiver->head->number < receiver->head->next->number)
			swap(receiver->head, receiver->head->next, r);
		push_first(receiver, sender);
		push_first(receiver, sender);
		rra_list(receiver, r);
		push_first(receiver, sender);
		rra_list(sender, s);
		rra_list(sender, s);
		if (sender->head->number > sender->head->next->number)
			swap(sender->head, sender->head->next, s);
		free(tab);
		//list_display(sender, receiver);
	}
}

void	find_algo_top_rec(t_list *stack_a, t_list *stack_b, int x)
{
	if (x == 2)
	{
		if (stack_a->head->number > stack_a->head->next->number)
			swap(stack_a->head,  stack_a->head->next, 'b');
	}
	if (x == 3)
	{
		//ft_putstr_fd("sort top three\n", 1);
		//list_display(stack_a, stack_b);
		sort_three_top_non_empty(stack_a, x);
		//list_display(stack_a, stack_b);
	}
	else if (x == 4)
	{
		//ft_putstr_fd("sort top four\n", 1);
		//list_display(stack_a, stack_b);
		sort_four_top_non_empty(stack_a, stack_b, x, 'a', 'b');
		//list_display(stack_a, stack_b);
	}
	else if (x == 5)
	{
		//ft_putstr_fd("sort top five\n", 1);
		//list_display(stack_a, stack_b);
		sort_five_top_non_empty(stack_a, stack_b, x, 'a', 'b');
		//list_display(stack_a, stack_b);	
	}
}