/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:03:31 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/11 21:36:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	add_index(t_list *list)
{
	t_node	*iterator;
	long	i;

	if (!list)
		return ;
	i = 0;
	iterator = list->head;
	while (iterator != NULL)
	{
		iterator->index = i;
		iterator = iterator->next;
		i++;
	}
}

long	list_filler(int argc, char **argv, t_list *list)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		list_end(list, argv[i]);
		i++;
	}
	add_index(list);
	return (1);
}

void	chose_algo(int argc, t_list *stack)
{
	if (argc == 3)
	{
		if (stack->head->number > stack->head->next->number)
			write(1, "sa\n", 3);
	}
	else if (argc == 4)
		three_arg_maestro(stack);
	else if (argc == 5)
		small_insertion(stack);
	else if (argc == 6)
		five_arg_maestro(stack);
	else
		big_algo_maestro(stack);
}

void	chose_algo_via_big(int argc, t_list *stack)
{
	if (argc == 3)
	{
		if (stack->head->number > stack->head->next->number)
			swap(stack->head, stack->head->next, 'a', stack->l_co);
	}
	else if (argc == 4)
		b_three_arg(stack);
	else if (argc == 5)
		b_insertion(stack);
	else if (argc == 6)
		b_five(stack);
}
