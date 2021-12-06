/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:29:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	g_swap(t_node *first, t_node *second, char c)
{
	long	tmp;

	if (!first || !second)
		return ;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	if (c == 's')
		return ;
	else if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	g_push_first(t_list *sender, t_list *receiver)
{
	t_node	*tmp;
	char	*str;

	if (!sender || !sender->head)
		return ;
	str = ft_itoa(sender->head->number);
	receiver = list_start(receiver, str);
	tmp = sender->head;
	sender->length--;
	if (sender->length == 0)
	{
		sender->head = NULL;
		sender->tail = NULL;
	}
	else
	{
		sender->head = sender->head->next;
		sender->head->previous = NULL;
	}
	if (sender->c == 'a')
		write(1, "pb\n", 3);
	else if (sender->c == 'b')
		write(1, "pa\n", 3);
	free(tmp);
	free(str);
}
