/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/10 23:09:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

//b_size
//void	order_three(t_list *stack_a)
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

int		find_tab_mid(int *tab, int b_side)
{
	int	mid;

	if (b_side % 2 == 0)
		mid = tab[(b_side/ 2) - 1];
	else
		mid = tab[(b_side / 2)];
	return (mid);	
}

int	*create_tab( int size, t_list *stack)
{
	int i;
	int	*tab;
	t_node	*node;

	tab = malloc(sizeof(int) * size);
	node = stack->head;
	i = -1;
	tab = malloc (sizeof(int) * size);
	while (++i < size && node)
	{
		tab[i] = node->number;
		node = node->next;
	}
	ft_sort_int_tab(tab, size);
	return (tab);
}

void	mid_voyager(t_saved_mediane *mid, t_list *stack_a, t_list *stack_b)
{
	t_mediane_nodes *iter;
	int				*tab;
	int				i;
	int				ra;

	ra = 0;
	iter = mid->head->next;
	//ft_putnbr_fd(iter->mediane, 1);
	tab = create_tab(iter->b_side, stack_b);
	i = -1;
	iter->mediane = find_tab_mid(tab, iter->b_side);
	//push_above_mid_a(stack_b, stack_a, iter->mediane, iter);
	while (++i < iter->b_side)
	{
		//ft_putstr_fd("KENXI", 1);
		if (stack_b->head->number > iter->mediane)
		{
			push_first(stack_b, stack_a);
		}
		else
		{
			ft_putstr_fd("yokai: ", 1);
			ft_putnbr_fd(stack_b->head->number, 1);
			ft_putstr_fd("\n", 1);
			ra_list(stack_b, 'b');
			ra++;
		}
	}
	i = -1;
	while (++i < ra)
		rra_list(stack_b, 'b');
	sort_three_non_empty(stack_b, stack_a, 15, 'b', 'a');
	list_display(stack_a, stack_b);
	free(tab);

}


void	recursive_sort(t_list *stack_a, t_list *stack_b)
{
	int med_a;
	int	x;

	med_a = find_mid(stack_a);
	x = push_bajo_mid(stack_a, stack_b, med_a);
	//list_display(stack_a, stack_b);
	if (stack_a->length > 5)
		recursive_sort(stack_a, stack_b);
	else if(stack_a->length <= 5)
		chose_algo(stack_a->length + 1, stack_a);
	if (x <= 5)
		find_algo_rec(stack_a, stack_b, x);
	else if (x <= 10)
	{
		send_b_to_a(stack_b, stack_a);
	}
	//list_display(stack_a, stack_b);
	//if (x <= 10)
		
}

void	big_algo_maestro(t_list *stack_a)
{
	//int		middle;
	t_list	*stack_b;
	//t_saved_mediane	*mid;

	//printf("LENGTH %d\n", stack_a->length);
	stack_b = init_list();
	recursive_sort(stack_a, stack_b);
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