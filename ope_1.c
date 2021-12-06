/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:31:16 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	swap(t_node *first, t_node *second, char c, t_write *l_com)
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
		add_commands_start(l_com, "sa\n");
	else if (c == 'b')
		add_commands_start(l_com, "sb\n");
}

void	double_swap(t_list *list_1, t_list *list_2)
{
	swap(list_1->head, list_1->head->next, 's', list_1->l_co);
	swap(list_2->head, list_2->head->next, 's', list_2->l_co);
	add_commands_start(list_1->l_co, "ss\n");
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
	if (sender->c == 'a')
		add_commands_start(sender->l_co, "pb\n");
	else
		add_commands_start(receiver->l_co, "pa\n");
	free(tmp);
	free(str);
}
