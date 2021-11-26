/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/25 11:53:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	swap(t_node *first, t_node *second, char c, t_write *l_com)
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
		add_commands_start(l_com, "sa\n");
	else
		add_commands_start(l_com, "sb\n");
}

// void	double_swap(t_list *list_1, t_list *list_2)
// {
// 	swap(list_1->head, list_1->head->next, list_1->c);
// 	swap(list_2->head, list_2->head->next, list_2->c);
// }

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
		sender->l_co = add_commands_start(sender->l_co, "pa\n");
	else
		receiver->l_co = add_commands_start(receiver->l_co, "pb\n");
	free(tmp);
	free(str);
}
