/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_sort_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:11:09 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/17 23:32:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/push_swap.h"

void	ft_swap(int *tab, int i, int j)
{
	int	t_tab;

	t_tab = tab[i];
	tab[i] = tab[j];
	//printf("SALUT tab[j] = %d\n", tab[j]);
	tab[j] = t_tab;
}

int 	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	*n_tab;
	int	j;

	n_tab = malloc(sizeof(int) * size);
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
}
