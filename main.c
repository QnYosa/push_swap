/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/21 23:41:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	push_swap(int argc, char **argv, t_list *list)
{
	t_list		*stack_b;

	stack_b = init_list();
	if (!errors_main(argc, argv))
		return ;
	list_display(list, stack_b);
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
	// if (!is_sorted(list))
	// 	return (0);
	push_swap(argc, argv, list);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	list = NULL;
	list = init_list();
	if (!list_filler(argc, argv, list))
	{
		ft_putstr_fd("Nothing to do.\n", 1);
		return (0);
	}
	return (0);
}
