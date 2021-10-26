/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:21:55 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/24 16:10:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	list_display(t_list *list, t_list *listb)
{
	t_node	*tmp;
	t_node	*tmp_b;

	if (!list || !listb)
		return ;
	tmp = list->head;
	tmp_b = listb->head;
	while (tmp != NULL || tmp_b != NULL)
	{
		ft_putstr_fd("||\t", 1);
		if (tmp)
		{
			ft_putnbr_fd(tmp->number, 1);
			tmp = tmp->next;
		}
		ft_putstr_fd("\t||\t", 1);
		if (tmp_b)
		{
			ft_putnbr_fd(tmp_b->number, 1);
			tmp_b = tmp_b->next;
		}
		ft_putstr_fd("\t||\t\n", 1);
	}
	write(1, "====================================\n", 38);
}

void	one_list_display(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return ;
	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putstr_fd("||\t", 1);
		if (tmp)
		{
			ft_putnbr_fd(tmp->number, 1);
			tmp = tmp->next;
		}
		ft_putstr_fd("\t||\t\n", 1);
	}
	write(1, "====================================\n", 38);
}
