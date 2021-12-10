/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:56:03 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 16:01:37 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	arg_to_com(int argc, char **argv, t_write *com)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
		add_commands_start(com, argv[i]);
}



// int parser_tester(int argc, char **argv, t_*list *numbers)
// {
// }
