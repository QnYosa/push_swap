/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/18 15:24:59 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SPACESDIGITS "0123456789-+ \t\v\n\f\r"

typedef struct s_mediane_nodes
{
	int				mediane;
	int				max;
	int				min;
	int				index;
	int				b_side;
	int				a_side;
	int				length;
	
	struct s_mediane_nodes	*previous;
	struct s_mediane_nodes	*next;
}	t_mediane_nodes;

typedef	struct s_saved_mediane
{
	struct s_mediane_nodes	*head;
	struct s_mediane_nodes	*tail;
	int				length;
} t_saved_mediane;

typedef struct s_trio
{
	int	up;
	int	mid_up;
	int	mid_down;
	int	down;
	int	*tab;
}	t_trio;

/* ERRORS */
int		errors_main(int argc, char **argv);

/* CHECK */
int		is_sorted(t_list *stack);

/* OPERATIONS */
void	ra_list(t_list *list, char c);
void	rra_list(t_list *list, char c);
void	swap(t_node *first, t_node *second, char c);
void	push_first(t_list *sender, t_list *receiver);

/* LEAKS */
void	delete_list(t_list **list);
void	delete_d_tab(int argc, char **d_tab);
void	delete_mid(t_saved_mediane **list);

/* ARGUMENTS */
char	*strjoin_double_tab(char *tmp, char **d_tab, t_container *n_argus);
void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus);

/* 	LIST IMPLEMENTATION */
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

/* 	AFFICHAGE */
void	list_display(t_list *list, t_list *listb);
void	one_list_display(t_list *list);
void	mediane_display(t_saved_mediane *mid);

/*			PODIUM				*/
void	init_podium_main(t_trio *podium, t_list *stack_a, t_list *stack_b);

/* TABS */
void	ft_swap(int *tab, int i, int j);
int		*ft_sort_int_tab(int *tab, int size);
void	ft_rev_int_tab(int *tab, int size);
void	malloc_tab(int n, int *tab);
int		*create_tab( int size, t_list *stack);

/*			 FILL TAB 			*/
void	up_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	midup_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	midlow_fill(int *tab, t_list *stack_a, t_list *stack_b);
void	down_fill(int *tab, t_list *stack_a, t_list *stack_b);

/*			CHOSE OPERATION       */
void	chose_algo(int argc, t_list *stack);
void	tab_filler(int n, t_trio *podium, t_list *stack_a, t_list *stack_b);

/* ALGO */
int		find_index_max(t_list *stack, int max);
int		find_index_min(t_list *stack, int min);
int		find_min(t_list *stack_a);
void	small_insertion(t_list *stack_a);
void	five_arg_maestro(t_list *stack_a);
void	big_algo_maestro(t_list *stack_a);


/* 			3 - ARGS    */
void	three_arg_maestro(t_list *stack_a);
void	small_insertion(t_list *stack_a);

/* 			MATHS		*/
int				find_mid(t_list *stack);
void			push_under_mid(t_list *sender, t_list *receiver, int mid, t_mediane_nodes *median);
int				push_above_mid_a(t_list *sender, t_list *receiver, int mid);
t_saved_mediane	*init_list_mediane(void);
t_saved_mediane	*list_mediane_start(t_saved_mediane *list, t_list *stack);
int				find_max(t_list *stack_a);
void			add_mid_index(t_saved_mediane *mid);
int				to_empty_unsorted_top(int b_side, t_list *sender, t_list *receiver);
void			sort_three_non_empty(t_list *sender, t_list *receiver, int x, char s, char r);
int				count_above_mid(t_list *sender, int mid);
int				find_mid_x(t_list *stack, int length);
int				push_above_mid_x(t_list *sender, t_list *receiver, int mid, int x);
/*			RECURSIVE		*/
void				recursive_sort(t_list *stack_a, t_list *stack_b, int len);
int				push_bajo_mid(t_list *sender, t_list *receiver, int mid);
void			find_algo_rec(t_list *stack_a, t_list *stack_b, int x);
int				push_arriba_mid(t_list *sender, t_list *receiver, int mid);
void			send_b_to_a(t_list *sender, t_list *receiver, int x);
void			find_algo_top_rec(t_list *stack_a, t_list *stack_b, int x);
/* 			OPTI			*/
int				is_next(t_list *stack_a, t_list *stack_b);
#endif