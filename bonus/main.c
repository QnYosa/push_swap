/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:16:31 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/12 00:09:12 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include "get_next_line.h"

int	translate_2(t_list *s_a, t_list *s_b, char *buffer)
{
	if (!ft_strncmp(buffer, "sb"))
	{
		if (s_b && s_b->head && s_b->head->next)
			swap(s_b->head, s_b->head->next, 'b', s_a->l_co);
		return (0);
	}
	else if (!ft_strncmp(buffer, "ss"))
	{
		double_swap(s_a, s_b);
		return (0);
	}
	else if (!ft_strncmp(buffer, "rr"))
	{
		rr_91(s_a, s_b);
		return (0);
	}
	else if (!ft_strncmp(buffer, "rrr"))
	{
		rrr(s_a, s_b);
		return (0);
	}
	else if (!ft_strncmp (buffer, "pa"))
	{
		push_first(s_a, s_b);
		return (0);
	}
	else if (!ft_strncmp(buffer, "pb"))
	{
		push_first(s_b, s_a);
		return (0);
	}
	return (1);
}

int	translate(t_list *s_a, t_list *s_b, char *buffer)
{
	if (!ft_strncmp(buffer, "ra"))
	{
		ra_list(s_a, 'a', s_a->l_co);
		return (0);
	}
	else if (!ft_strncmp(buffer, "rb"))
	{
		ra_list(s_b, 'b', s_a->l_co);
		return (0);
	}
	else if (!ft_strncmp(buffer, "rra"))
	{
		rra_list(s_a, 'a', s_a->l_co);
		return (0);
	}
	else if (!ft_strncmp(buffer, "rrb"))
	{
		rra_list(s_b, 'b', s_a->l_co);
		return (0);
	}
	else if (!ft_strncmp(buffer, "sa"))
	{
		swap(s_a->head, s_a->head->next, 'a', s_a->l_co);
		return (0);
	}
	return (translate_2(s_a, s_b, buffer));
}

int	checker(t_list *s_a, t_list *s_b)
{	
	char	*buffer;
	int		state;

	buffer = 0;
	state = get_next_line(0, &buffer);
	while (state == 1)
	{
		if (translate(s_a, s_b, buffer) == 1)
		{
			get_next_line(-1, &buffer);
			state = 1;
			break ;
		}
		free(buffer);
		buffer = 0;
		state = get_next_line(0, &buffer);
	}
	if (buffer)
		free(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*s_a;
	t_list	*s_b;

	if (ac < 3 || !errors_main(ac, av))
		return (0);
	s_a = init_list();
	s_b = init_list();
	s_a->c = 'a';
	s_b->c = 'b';
	if (!list_filler(ac, av, s_a) || is_sorted(s_a))
	{
		delete_list(&s_a);
		delete_list(&s_b);
		return (0);
	}
	if (checker(s_a, s_b) == 0 && s_b->length == 0 && is_sorted(s_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_list(&s_a);
	delete_list(&s_b);
}
