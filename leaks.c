/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:37:33 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/05 22:56:13 by dyoula           ###   ########.fr       */
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

void	delete_d_tab(int argc, char **d_tab)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		// ft_putstr_fd("delete d_tab", 1);
		// ft_putnbr_fd(i, 1);
		// ft_putchar_fd('\n', 1);
		// ft_putstr_fd(d_tab[i], 1);
		// ft_putchar_fd('\n', 1);
		free(d_tab[i]);
		i++;
	}
	free(d_tab);
}