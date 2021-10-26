/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/26 14:55:13 by dyoula           ###   ########.fr       */
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
	list_display(list, stack_b);
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
		arg_split_to_list(d_tab, list, &n_argus);
		i++;
	}
	add_index(list);
	return (1);
}

void	chose_algo(int argc, t_list *stack)
{
	if (argc == 4)
		three_arg_maestro(stack);
	if (argc == 5)
		small_insertion(stack);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	list = NULL;
	list = init_list();
	if (!list_filler(argc, argv, list)/* || is_sorted(list)*/)
	{
		ft_putstr_fd("Nothing to do.\n", 1);
		return (0);
	}
	one_list_display(list);
	chose_algo(argc, list);
	//push_swap(argc, argv, list);
	delete_list(&list);
	return (0);
}
