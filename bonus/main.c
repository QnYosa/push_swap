/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:16:31 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/08 20:13:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	translate(t_list *s_a, t_list *s_b, char *buffer)
{
	if (compare(buffer, "ra\n"))
		ra_list(s_a, 'a', s_a->l_co);
	else if (compare(buffer, "rb\n"))
		ra_list(s_b, 'b', s_a->l_co);
	else if (compare(buffer, "rra\n"))
		rra_list(s_a, 'a', s_a->l_co);
	else if (compare(buffer, "rrb\n"))
		rra_list(s_b, 'b', s_a->l_co);
	else if (compare(buffer, "sa\n"))
		swap(s_a->head, s_a->head->next, 'a', s_a->l_co);
	else if (compare(buffer, "sb\n"))
		swap(s_b->head, s_b->head->next, 'b', s_a->l_co);
	else if (compare(buffer, "ss\n"))
		double_swap(s_a, s_b);
	else if (compare(buffer, "rr\n"))
		rr_91(s_a, s_b);
	else if (compare(buffer, "rrr\n"))
		rrr(s_a, s_b);
	else if (compare (buffer, "pa\n"))
		push_first(s_a, s_b);
	else if (compare(buffer, "pb\n"))
		push_first(s_b, s_a);
}

void	checker(t_list *s_a, t_list *s_b)
{
	char *buffer;
	int	size;

	buffer = (char*)malloc(sizeof(char) * 5);
	size = read(0, buffer, 4);
	if (size == -1)
	{
		write(1, "Error\n", 6);
		return ;
	}
	while (size)
	{
		translate(s_a, s_b, buffer);
		size = read(0, buffer, 4);
		if (size == -1)
			write(1, "Error\n", 6);
	}
	free(buffer);
}

int main(int ac, char **av)
{
	t_write	*coms;
	t_list	*s_a;
	t_list	*s_b;
	char	*buf;
	if (ac < 3 || !errors_main(ac, av))
		return (0);
	s_a = NULL;
	s_a = init_list();
	s_b = NULL;
	s_a = init_list();
	if (!list_filler(ac, av, s_a) || is_sorted(s_a))
	{
		delete_list(&s_a);
		delete_list(&s_b);
		return (0);
	}
	checker(s_a, s_b);	
}
