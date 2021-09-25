/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:06:23 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/25 18:39:02 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	*ft_lstnew_counter(int n, int *i)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->number = n;
	new->next = NULL;
	i++;
	return (new);
}

void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus)
{
	int	i;

	i = 0;
	while (i < n_argus->n_tabs)
	{
		ft_lstadd_back_p(&list, ft_lstnew_p(d_tab[i]));
		i++;
	}
}
