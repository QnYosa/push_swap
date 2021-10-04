/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:18:32 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/04 15:08:03 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	*list_insert_norm(t_node *tmp, t_list *list, char *content)
{
	if (tmp->next == NULL)
		list = list_end(list, content);
	else if (tmp->previous == NULL)
		list = list_start(list, content);
	return (list);
}

t_node	*malloc_node_norm(t_node *tmp, t_node *new, t_list *list, char *content)
{
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new = new_node(new, tmp, content, list);
	return (new);
}

void	list_display(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return ;
	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->number, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "NULL", ft_strlen("NULL") + 1);
	write(1, "\n", 1);
}
