/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/30 19:40:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"
/*
t_first	*init_list(t_first *first, char *str)
{
	first = malloc(sizeof(first));
	if (!first)
		return (0);
	list->first = ft_lstnew_p(str);
	return (first);
}

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
	{
		//printf("je floppe\n");
		return ;
	}
	if (!*alst)
	{
		*alst = new;
		printf("%d \n", (*alst)->number);
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
	ft_lstiter(list, f);
}

void arg_management(t_first list, )
{
	char	**d_tab;
}

int	main(int argc, char **argv)
{
	t_first		*list;
	t_list		*element;
	t_container	n_argus;
	int			i;

	i = 0;
	if (argc < 2 || !errors_main(argc, argv)) // que chiffres et spaces
		return (0);
	while (i < argc)
	{
		d_tab = ft_split(argv[i], " \t\v\n\f\r", n_argus, i); //work
		if (i == 1)
			t_first = init_list(list, d_tab[0]);
		arg_split_to_list(d_tab, list, n_argus, i);
		i++;
	}
	push_swap(argc, argv, list, &n_argus);
}
*/

void	arg_management()
{
	
}

int	main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	list = init_list();
}
