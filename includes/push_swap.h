/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/30 18:02:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SPACESDIGITS "0123456789 \t\v\n\f\r"

int		errors_main(int argc, char **argv);
char	*strjoin_double_tab(char *tmp, char **d_tab, t_container *n_argus);
void	ft_lstadd_back_p(t_list **alst, t_list *new);
void	arg_split_to_list(char **d_tab, t_list *list, t_container *n_argus);
t_list	*ft_lstnew_p(char *content);
t_list	init_list(void);

#endif