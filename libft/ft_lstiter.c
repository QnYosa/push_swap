/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:14:29 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/04 13:50:39 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int, int))
{
	t_node	*tmp;

	(void)f;
	if (!lst || !f)
		return ;
	tmp = lst->head;
	if (lst)
	{
		while (tmp)
		{
			ft_putnbr_fd(tmp->number, 1);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
}
