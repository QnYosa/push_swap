/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:15:04 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/28 17:59:33 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nb_elements;
	t_list	*tmp;

	if (lst == NULL)
		return (0);
	else
	{
		tmp = lst->next;
		nb_elements = 0;
		while (tmp)
		{
			nb_elements++;
			tmp = tmp->next;
		}
	}
	return (nb_elements + 1);
}
