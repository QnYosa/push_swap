/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:56:03 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/28 19:17:08 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	arg_to_com(int  argc, char **argv, t_write *com)
{
	int i;

	i = 0;
	while (++i < argc - 1)
		add_commands_start(com, argv[i]);
}

void	translate(t_stack *s_a, t_stack *s_b, t_write *com)
{
	t_commands	*i;

	i = com->head;
	while (i)
	{
		if (compare(com->command, "ra\n"))
			ra_list(s_a, 'a', s_a->l_com);
		else if (compare(com->command, "rb\n"))
			ra_list(s_b, 'b', s_a->l_com);
		else if (compare(com->command, "rra\n"))
			rra_list(s_a, 'a', s_a->l_com);
		else if (compare(com->command, 'rrb\n'))
			rra_list(s_b, 'b', s_a->l_com);
		else if (compare(com->command, "sa\n")
			swap(s_a->head, s_a->head->next, 'a', s_a->l_com);
		else if (compare(com->command, "sb\n")
			swap(s_b->head, s_b->head->next, 'b', s_a->l_com);
		else if (compare(com->command, "ss\n"))
			double_swap(s_a, s_b);
		else if (compare(com->command, "rr\n"))
			rr91(s_a, s_b);
		else if (compare(com->command, "rrr\n"))
			rrr(s_a, s_b);
		else if (compare (com->command, "pa\n"))
			push_first(s_a, s_b);
		else if (compare(com->command, "pb\n"))
			push_first(s_b, s_a);
	}
}

int parser_tester(int argc, char **argv, t_*list *numbers)
{
	
}

int main (int argc, char **argv)
{
	t_write	*coms;
	t_stack	*s_a;
	t_stack	*s_b;

	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	s_a = NULL;
	s_a = init_list();
	if (!list_filler(argc, argv, list) || is_sorted(list))
	{
		delete_list(&s_a);
		delete_list(&s_b);
		return (0);
	}
	coms = init_write();
	arg_to_com(argc, argv, coms);
	display_commands(coms);
}
