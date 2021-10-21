/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/21 22:33:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	swap_a(t_node *first, t_node *second)
{
	int	tmp;

	if (!first || !second)
		return ;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_node *first, t_node *second)
{
	int	tmp;

	if (!first || !second)
		return ;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	write(1, "sb\n", 3);
}

void	double_swap(t_list *list_1, t_list *list_2)
{
	swap_a(list_1->head, list_1->head->next);
	swap_b(list_2->head, list_2->head->next);
}

void	push_first(t_list *sender, t_list *receiver)
{
	t_node	*tmp;

	if (!sender || !sender->head)
		return ;
	receiver = list_start(receiver, ft_itoa(sender->head->number));
	tmp = sender->head;
	sender->head = sender->head->next;
	sender->head->previous = NULL;
	sender->length--;
	receiver->length++;
	free(tmp);
}
