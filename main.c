/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/05 23:26:45 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void	push_swap(int argc, char **argv, t_list *list)
{
	int			i;
	t_list		*stack_b;

	stack_b = init_list();
	i = 1;
	if (!errors_main(argc, argv))
		return ;
	push_first(list, stack_b);
	list_display(list, stack_b);
	push_first(list, stack_b);
	list_display(list, stack_b);
	//delete_list(&list);
	//delete_list(&stack_b);
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
	push_swap(argc, argv, list);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	list = init_list();
	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	list_filler(argc, argv, list);
}
