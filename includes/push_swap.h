/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/20 22:14:21 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SPACESDIGITS "0123456789-+ \t\v\n\f\r"

typedef struct s_trio
{
	int	up;
	int	mid_up;
	int	mid_down;
	int	down;
}	t_trio;

/* ERRORS */
int		errors_main(int argc, char **argv);

/* CHECK */
int		is_sorted(t_list *stack);

/* OPERATIONS */
void	ra_list(t_list *list);
void	rra_list(t_list *list);
void	swap_a(t_node *first, t_node *second);
void	swap_b(t_node *first, t_node *second);
void	push_first(t_list *sender, t_list *receiver);

/* LEAKS */
void	delete_list(t_list **list);

/* ARGUMENTS */
char	*strjoin_double_tab(char *tmp, char **d_tab, t_container *n_argus);
void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus);

/* LIST IMPLEMENTATION */
t_list	*ft_lstnew_p(char *content);
t_list	*init_list(void);
t_list	*list_insert_norm(t_node *tmp, t_list *list, char *content);
t_node	*malloc_node_norm(t_node *tmp, t_node *new, t_list *list, \
char *content);
void	ft_lstadd_back_p(t_list **alst, t_list *new);
t_list	*list_end(t_list *list, char *content);
t_list	*list_start(t_list *list, char *content);
t_node	*new_node(t_node *new, t_node *tmp, char *content, t_list *list);
void	add_index(t_list *list);

/* AFFICHAGE */
void	list_display(t_list *list, t_list *listb);

/* TABS */
void	ft_swap(int *tab, int i, int j);
void	ft_sort_int_tab(int *tab, int size);
void	ft_rev_int_tab(int *tab, int size);

/* FILL TAB */
void	up_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	midup_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	midlow_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	down_fill(int *tab, t_list *stack_a, t_list *stack_b);

#endif