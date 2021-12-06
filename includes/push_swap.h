/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/06 00:02:05 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>

# define SPACESDIGITS "0123456789-+ \t\v\n\f\r"

/* ERRORS */
long			errors_main(long argc, char **argv);
long			twins(t_list *l);
/* CHECK */
long			is_sorted(t_list *stack);
long			is_sorted_end(t_list *stack);

/* OPERATIONS */
void			ra_list(t_list *list, char c, t_write *l_com);
void			rra_list(t_list *list, char c, t_write *l_com);
void			swap(t_node *first, t_node *second, char c, t_write *l_com);
void			push_first(t_list *sender, t_list *receiver);
void			un_ra_list(t_list *stack, long x, char c, t_write *l_com);
void			rr_91(t_list *a, t_list *b);
void			rrr(t_list *a, t_list *b);
void			double_swap(t_list *list_1, t_list *list_2);

/* LEAKS */
void			delete_list(t_list **list);
void			delete_d_tab(int argc, char **d_tab);
void			free_commands(t_write **l);

/* 	LIST IMPLEMENTATION */
t_list			*ft_lstnew_p(char *content);
t_list			*init_list(void);
t_list			*list_insert_norm(t_node *tmp, t_list *list, char *content);
t_node			*malloc_node_norm(t_node *tmp, t_node *new, t_list *list, \
char *content);
void			ft_lstadd_back_p(t_list **alst, t_list *new);
t_list			*list_end(t_list *list, char *content);
t_list			*list_start(t_list *list, char *content);
t_node			*new_node(t_node *new, t_node *tmp, char *content, t_list \
*list);
void			add_index(t_list *list);

/* 	AFFICHAGE */
void			list_display(t_list *list, t_list *listb);
void			one_list_display(t_list *list);

/* TABS */
void			ft_swap(long *tab, long i, long j);
long			*ft_sort_int_tab(long *tab, long size);
void			ft_rev_int_tab(long *tab, long size);
void			malloc_tab(long n, long *tab);
long			*create_tab(long size, t_list *stack);

/*			CHOSE OPERATION       */
void			chose_algo(int argc, t_list *stack);

/* ALGO */
long			find_index_max(t_list *stack, long max);
long			find_index_min(t_list *stack, long min);
long			find_min(t_list *stack_a);
void			small_insertion(t_list *stack_a);
void			five_arg_maestro(t_list *stack_a);
void			big_algo_maestro(t_list *stack_a);

/* 			3 - ARGS    */
void			three_arg_maestro(t_list *stack_a);
void			small_insertion(t_list *stack_a);

/* 			MATHS		*/
long			is_max(t_list *stack_a, long n);
long			find_mid(t_list *stack);
long			find_max(t_list *stack_a);
long			to_empty_unsorted_top(long b_side, t_list *sender, \
t_list *receiver);
void			sort_three_non_empty(t_list *sender, t_list *receiver, \
char s, char r);
void			sort_three_top_non_empty(t_list *stack, long x);
long			count_above_mid(t_list *sender, long mid);
long			find_mid_x(t_list *stack, long length);
long			push_above_mid_x(t_list *sender, t_list *receiver, \
long mid, long x);
/*			RECURSIVE		*/
void			recursive_sort(t_list *stack_a, t_list *stack_b, long len);
long			push_bajo_mid(t_list *sender, t_list *receiver, long mid);
void			find_algo_rec(t_list *stack_a, t_list *stack_b, long x);
long			push_arriba_mid(t_list *sender, t_list *receiver, long mid);
void			send_b_to_a(t_list *sender, t_list *receiver, long x);
void			find_algo_top_rec(t_list *stack_a, t_list *stack_b, long x);
/* 			OPTI			*/
long			is_next(t_list *stack_a, t_list *stack_b);
long			find_quarter(t_list *stack);
long			*is_next_top_a(long *tab, long *touched, long size, \
t_list *stack_a);
void			add_commands_start(t_write *write_, char *content);
t_write			*init_write(void);
void			display_commands(t_write *l);
void			delete_useless(t_write **l);
long			is_next_from(t_list *stack_a, long above);
long			optimizer(t_commands **s1, t_commands *s2);
long			rotate_b_killer(t_commands **s1);
long			rotate_rb_killer(t_commands **s1);
long			rotate_a_killer(t_commands **s1);
long			rotate_ra_killer(t_commands **s1);
long			delete_c(t_commands **s1, t_commands**s2);
/*			FIX					*/
void			g_swap(t_node *first, t_node *second, char c);
void			g_push_first(t_list *sender, t_list *receiver);
void			g_ra_list(t_list *list, char c);
void			g_rra_list(t_list *list, char c);

void			b_three_arg(t_list *stack_a);
void			b_insertion(t_list *stack_a);
void			b_five(t_list *stack_a);
void			chose_algo_via_big(int argc, t_list *stack);
long			compare(char *s1, char *s2);
long			comp_max(char *s1, char *s2);
/*			NORM				*/
void			s_t_t_n_e(t_list *stack, long *tab);
void			s_f_t_n_e(t_list *sender, t_list *receiver, long *tab, long ra);
long			ra_opt_stne(long ra, t_list *sender, long *tab, long x);
#endif