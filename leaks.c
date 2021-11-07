/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:37:33 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/06 19:42:51 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	delete_list(t_list **list)
{
	t_node				*tmp;
	t_node				*del;
	unsigned int		i;

	i = 0;
	if (*list == NULL)
		return ;
	tmp = (*list)->head;
	while (tmp != NULL && i <= (*list)->length)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(*list), *list = NULL;
}

void	delete_mid(t_saved_mediane **list)
{
	t_mediane_nodes				*tmp;
	t_mediane_nodes				*del;
	unsigned int		i;

	i = 0;
	if (*list == NULL)
		return ;
	tmp = (*list)->head;
	while (tmp != NULL /* && i <= (*list)->length*/)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(*list), *list = NULL;
}

void	delete_d_tab(int argc, char **d_tab)
{
	int	i;

	i = -1;
	while (++i < argc)
		free(d_tab[i]);
	free(d_tab);
}
