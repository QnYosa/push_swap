/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_sort_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:11:09 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/05 22:34:59 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ft_swap(long *tab, long i, long j)
{
	long	t_tab;

	t_tab = tab[i];
	tab[i] = tab[j];
	tab[j] = t_tab;
}

long	*ft_sort_int_tab(long *tab, long size)
{
	long	i;
	long	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			ft_swap(tab, i, j);
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	return (tab);
}

void	ft_rev_int_tab(long *tab, long size)
{
	long	i;
	long	*n_tab;
	long	j;

	n_tab = malloc(sizeof(long) * size);
	if (!n_tab)
		return ;
	j = 0;
	i = 0;
	while (i < size)
	{
		n_tab[i] = tab[i];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		tab[j] = n_tab[i];
		j++;
		i--;
	}
	free(n_tab);
}
