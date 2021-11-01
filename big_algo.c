/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:53:24 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/01 18:53:25 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	big_algo_maestro(t_list *stack_a)
{
	t_list	*stack_b;
	int		mid;

	stack_b = init_list();
	mid = find_mid(stack_a);
	push_under_mid(stack_a, stack_b, mid);
	list_display(stack_a, stack_b);
}