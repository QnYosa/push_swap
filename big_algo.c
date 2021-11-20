/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/20 15:36:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int is_next(t_list *stack_a, t_list *stack_b)
{
	int i;
	int next;

	next = 0;
	i = 0;
	while (stack_a->tab[i] != stack_a->head->number)
		i++;
	if (i < (int)(stack_b->length + stack_a->length) - 2)
	{
		printf("yo\n");
		if (stack_a->tab[i + 1] == stack_b->head->number)
		{
			push_first(stack_b, stack_a);
			next++;
		}
		if (stack_a->tab[i + 1] == stack_b->head->next->number)
		{
			printf("SWAP PUSH\n");
			swap(stack_b->head, stack_b->head->next, 'b');
			push_first(stack_b, stack_a);
			next++;
		}
	}
	return (next);
}

int	find_index_tab(int *tab, int number, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (tab[i] == number)
			return (i);
		i++;
	}
	return (i);
}

void	empty_mid(t_list *stack_b, int length)
{
	int	i;
	int	*sorted;
	t_node	*iter;
	
	iter = stack_b->head;
	sorted = malloc(sizeof(int) * length);
	if (!sorted)
		exit (0);
	i = 0;
	while (i < length && iter)
	{
		sorted[i] = iter->number;
		i++;
		iter = iter->next;
	}
	ft_sort_int_tab(sorted, length);
	iter = stack_b->head;
	i = 0;
	if (stack_b->head->number < stack_b->head->next->number)
		swap(stack_b->head, stack_b->head->next, 'b');
	free(sorted);
}


int	*create_tab( int size, t_list *stack)
{
	int i;
	int	*tab;
	t_node	*node;

	tab = malloc(sizeof(int) * size);
	node = stack->head;
	i = -1;
	while (++i < size && node)
	{
		tab[i] = node->number;
		node = node->next;
	}
	tab = ft_sort_int_tab(tab, size);
	return (tab);
}

void	recursive_sort(t_list *stack_a, t_list *stack_b, int len)
{
	int med_a;
	int	x;

	med_a = find_mid_x(stack_a, len);
	x = push_bajo_mid(stack_a, stack_b, med_a);
	if (len - x <= 5)
	{
		if (len - x == (int)stack_a->length)
			chose_algo(x + 1, stack_a);
		else
			find_algo_top_rec(stack_a, stack_b, len - x);
		//list_display(stack_a, stack_b);
	}
	else
		recursive_sort(stack_a, stack_b, len - x);
	if (x <= 5)
		find_algo_rec(stack_a, stack_b, x);
	else
		send_b_to_a(stack_b, stack_a, x);
	//list_display(stack_a, stack_b);
}

void	big_algo_maestro(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = init_list();
	stack_a->tab = create_tab(stack_a->length, stack_a);
	stack_a->quarter = find_quarter(stack_a);
	//printf("quarter = %d", stack_a->quarter);
	recursive_sort(stack_a, stack_b, stack_a->length);
	//list_display(stack_a, stack_b);
	free(stack_a->tab);
	delete_list(&stack_b);
}
