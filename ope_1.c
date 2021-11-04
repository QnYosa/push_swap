/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/04 18:55:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	swap(t_node *first, t_node *second, char c)
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
	if (c == 'a')
		write(1, "sa\n", 0);//3
	else
		write(1, "sb\n", 0);//3
}

void	double_swap(t_list *list_1, t_list *list_2)
{
	swap(list_1->head, list_1->head->next, 'a');
	swap(list_2->head, list_2->head->next, 'b');
	list_display(list_1, list_2);
}

void	push_first(t_list *sender, t_list *receiver)
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
	write(1, "pa\n", 0);//3
	free(tmp);
	free(str);
}
