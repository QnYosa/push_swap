/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:06:23 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/04 14:03:42 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus)
{
	int	i;

	i = 0;
	while (i < n_argus->n_tabs)
	{
		list_end(list, d_tab[i]);
		i++;
	}
}
