/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:02:18 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/24 23:33:51 by dyoula           ###   ########.fr       */
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

void	push_swap(int argc, char **argv, t_list *list, t_container *n_argus)
{
	int			i;
	void		(*f)(int, int);
	char		*tmp;
	char		**d_tab;

	f = &ft_putnbr_fd;
	i = 1;
	tmp = ft_strdup("");
	while (i < argc)
	{
		d_tab = ft_split(argv[i], " \t\v\n\f\r", n_argus); //work
		tmp = strjoin_double_tab(tmp, d_tab, n_argus);
		//printf("%s\n", tmp);
		i++;
	}
	//printf("%s\n", tmp);
	//ft_lstadd_back_p(&list, ft_lstnew_p(argv[i++]));
	//ft_lstiter(list, f);
	list = NULL;
}

int	main(int argc, char **argv)
{
	t_list		list;
	t_container	n_argus;

	//if (argc < 2 || !errors_main(argc, argv))
	//	return (0);
	push_swap(argc, argv, &list, &n_argus);
}
