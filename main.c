/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/01 15:09:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	push_swap(int argc, char **argv, t_list *list)
{
	t_list		*stack_b;
	int			i;

	i = -1;
	stack_b = init_list();
	if (!errors_main(argc, argv))
		return ;
	push_first(list, stack_b);
	push_first(list, stack_b);
	list_display(list, stack_b);
	while (++i < 2)
		chose_best_to_pop(list, stack_b);
	delete_list(&list);
	delete_list(&stack_b);
}

int	list_filler(int argc, char **argv, t_list *list)
{
	t_container	n_argus;
	char		**d_tab;
	int			i;

	i = 1;
	while (i < argc)
	{
		d_tab = ft_split(argv[i], " \t\v\n\f\r", &n_argus);
		if (!d_tab)
		{
			ft_putstr_fd("RAUS FDP\n", 1);
			exit(0);
		}
		arg_split_to_list(d_tab, list, &n_argus);
		delete_d_tab(n_argus.n_tabs, d_tab);
		i++;
	}
	add_index(list);
	return (1);
}

void	chose_algo(int argc, /*char **argv,*/ t_list *stack)
{
	if (argc == 4)
		three_arg_maestro(stack);
	else if (argc == 5)
		small_insertion(stack);
	else if (argc == 6)
		five_arg_maestro(stack);
	else
		big_algo_maestro(stack);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	list = NULL;
	list = init_list();
	if (!list_filler(argc, argv, list) || is_sorted(list))
	{
		delete_list(&list);
		return (0);
	}
	
	one_list_display(list);
	chose_algo(argc, list);
	one_list_display(list);
	delete_list(&list);
	return (0);
}
