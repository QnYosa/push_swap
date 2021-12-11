/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/11 23:54:53 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	int		i;

	i = 0;
	if (argc < 3 || !errors_main(argc, argv))
		return (0);
	list = NULL;
	list = init_list();
	list->c = 'a';
	while (++i < argc)
	{
		ft_atoi(argv[i]);
		if (!comp_max(argv[i], "2147483648") || ft_strlen(argv[i]) > 10)
		{
			write(1, "Error\n", 6);
			free(list);
			return (0);
		}
	}
	if (!list_filler(argc, argv, list) || is_sorted(list) || !twins(list))
	{
		delete_list(&list);
		return (0);
	}
	if (argc > 6)
		list->l_co = init_write();
	chose_algo(argc, list);
	if (argc > 6)
		free_commands(&list->l_co);
	delete_list(&list);
	return (0);
}
