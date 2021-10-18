/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/10/18 23:14:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SPACESDIGITS "0123456789-+ \t\v\n\f\r"

int		errors_main(int argc, char **argv);
char	*strjoin_double_tab(char *tmp, char **d_tab, t_container *n_argus);
void	ft_lstadd_back_p(t_list **alst, t_list *new);
void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus);
t_list	*ft_lstnew_p(char *content);
t_list	*init_list(void);
t_list	*list_insert_norm(t_node *tmp, t_list *list, char *content);
t_node	*malloc_node_norm(t_node *tmp, t_node *new, t_list *list, \
char *content);
t_list	*list_end(t_list *list, char *content);
t_list	*list_start(t_list *list, char *content);
t_node	*new_node(t_node *new, t_node *tmp, char *content, t_list *list);
void	list_display(t_list *list, t_list *listb);
void	swap_a(t_node *first, t_node *second);
void	swap_b(t_node *first, t_node *second);
void	push_first(t_list *sender, t_list *receiver);
void	delete_list(t_list **list);
void	ra_list(t_list *list);
void	rra_list(t_list *list);

#endif