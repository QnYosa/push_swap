/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 18:30:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

//b_size
//void	order_three(t_list *stack_a)
int is_next(t_list *stack_a, t_list *stack_b)
{
	int i;

	i = 0;
	while (stack_a->tab[i] != stack_a->head->number)
		i++;
	if (i < (int)(stack_b->length + stack_a->length) - 2)
	{
		if (stack_a->tab[i + 1] == stack_b->head->number)
		{
			printf("PUSH FIRST\n");
			push_first(stack_b, stack_a);
			return (1);
		}
		else if (stack_a->tab[i + 1] == stack_b->head->next->number)
		{
			printf("SWAP PUSH\n");
			swap(stack_b->head, stack_b->head->next, 'b');
			push_first(stack_b, stack_a);
			return (1);
		}
		// else if (tab[i + 1] == stack_b->tail->number)
		// {
		// 	rra
		// }
	}
	return (0);
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
	//int	index;
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
	//int med_x;

	med_a = find_mid_x(stack_a, len);
	x = push_bajo_mid(stack_a, stack_b, med_a);
	printf("recursive sort, med_a = %d, len = %d, x = %d\n", med_a, len, x);
	list_display(stack_a, stack_b);
	if (len - x <= 5)
	{
		printf("\trecursive_sort, if len - x <= 5, len - x = %d\n", len - x);
		if (len - x == (int)stack_a->length)
			chose_algo(x + 1, stack_a);
		else
			find_algo_top_rec(stack_a, stack_b, len - x);
		list_display(stack_a, stack_b);
	}
	else
		recursive_sort(stack_a, stack_b, len - x);
	if (x <= 5)
	{
		printf("\trecursive_sort, if x <= 5, x = %d\n", x);
		find_algo_rec(stack_a, stack_b, x);
		list_display(stack_a, stack_b);
	}
	else
	{
		send_b_to_a(stack_b, stack_a, x);
	}

	//if (x <= 10)
		
}

void	big_algo_maestro(t_list *stack_a)
{
	//int		middle;
	t_list	*stack_b;
	//t_saved_mediane	*mid;

	//printf("LENGTH %d\n", stack_a->length);
	stack_b = init_list();
	stack_a->tab = create_tab(stack_a->length, stack_a);
	recursive_sort(stack_a, stack_b, stack_a->length);
	list_display(stack_a, stack_b);
	delete_list(&stack_b);
	//mid = init_list_mediane();
	/*
	while (stack_a->length > 4)
	{
		list_mediane_start(mid, stack_a);
		middle = mid->head->mediane;
		push_under_mid(stack_a, stack_b, middle, mid->head);
		mid->head->max = find_max(stack_b);
		ft_putstr_fd("SDR: ", 1);
		ft_putnbr_fd(mid->head->max, 1);
		ft_putstr_fd("\n", 1);
		//list_display(stack_a, stack_b);
		//ft_putstr_fd("PASSAGE_MEDIANE\n", 1);
		//printf("HOLA MIDDLE %d\n b_side %d\n", middle, mid->head->b_side);
		add_mid_index(mid);
		mediane_display(mid);
		three_arg_maestro(stack_a);
		empty_mid(stack_b, mid->head->b_side);
		list_display(stack_a, stack_b);
	}
	//if (mid->head->b_side > 3)
	//	push_above_mid(stack_b, stack_a, middle, mid);
	//push_under_mid(stack_a, stack_b, middle, mid->head);
	mid->head->b_side = to_empty_unsorted_top(mid->head->b_side, stack_b, stack_a);
	list_display(stack_a, stack_b);
	// ft_putstr_fd("remains: ", 1);
	// ft_putnbr_fd(mid->head->b_side, 1);
	// ft_putstr_fd("\n", 1);
	mid_voyager(mid, stack_a, stack_b);
	delete_mid(&mid);
	*/
}

/*
	while (i < length && iter->next)
	{
		//index tab, number
		//index = find_index_tab(sorted, )
		if (stack_b->head->number == sorted[0])
		{
			push_first(stack_b, stack_a);
			ra_list(stack_a, 'a');
		}
		else if (stack_b->head->number == sorted[1])//sorted[index]
			ra_list(stack_b, 'b');
		else if (stack_b->head->number == sorted[2])
			ra_list(stack_b, 'b');
		else if (stack_b->head->number == sorted[3])
			push_first(stack_b, stack_a);
		else if (stack_b->head->number == sorted[4])
			push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		i++;
		iter = iter->next;
	}
		rra_list(stack_b, 'b');
		rra_list(stack_b, 'b');
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		push_first(stack_b, stack_a);
		push_first(stack_b, stack_a);
		if (stack_a->head->number > stack_a->head->next->number && stack_a->head->next)
			swap(stack_a->head, stack_a->head->next, 'a');
		rra_list(stack_a, 'a');
}
*/