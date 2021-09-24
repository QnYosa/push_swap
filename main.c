/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/24 19:13:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	*ft_lstnew_p(char *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->number = ft_atoi(content);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_p(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}

void	push_swap(int argc, char **argv)
{
	int			i;
	void		(*f)(int, int);
	t_list		*list;
	t_container	n_argus;

	f = &ft_putnbr_fd;
	i = 1;
	//list = ft_lstnew_p(argv[i++]);
	while (i < argc)
	{
		ft_lstadd_back_p(&list, ft_lstnew_p(argv[i++]));
	}
	ft_lstiter(list, f);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || !errors_main(argc, argv))
		return (0);
	push_swap(argc, argv);
}
