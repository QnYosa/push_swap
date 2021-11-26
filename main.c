/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/24 17:07:37 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

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
			exit(0);
		}
		arg_split_to_list(d_tab, list, &n_argus);
		delete_d_tab(n_argus.n_tabs, d_tab);
		i++;
	}
	add_index(list);
	return (1);
}

/*char **argv,*/
void	chose_algo(int argc, t_list *stack)
{
	if (argc == 3)
		if (stack->head->number < stack->head->next->number)
			swap(stack->head, stack->head->next, 'a', stack->l_co);
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
	list->l_co = init_write();
	chose_algo(argc, list);
	delete_list(&list);
	return (0);
}
