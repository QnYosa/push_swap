/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/25 18:52:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_list	*ft_lstnew_p(char *content)
{
	t_list	*new;

	printf("salut %s\n", content);
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

void	push_swap(int argc, char **argv, t_list *list, t_container *n_argus)
{
	int			i;
	void		(*f)(int, int);
	char		**d_tab;

	f = &ft_putnbr_fd;
	i = 1;
	list = NULL;
	if (!errors_main(argc, argv))
		return ;
	while (i < argc)
	{
		d_tab = ft_split(argv[i], " \t\v\n\f\r", n_argus); //work
		arg_split_to_list(d_tab, list, n_argus);
		i++;
	}
	ft_lstiter(list, f);
}

int	main(int argc, char **argv)
{
	t_list		*list;
	t_container	n_argus;

	if (argc < 2 || !errors_main(argc, argv)) // que chiffres et spaces
		return (0);
	push_swap(argc, argv, list, &n_argus);
}
