/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:26:35 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 17:02:23 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_commands
{
	struct s_commands	*previous;
	struct s_commands	*next;
	char				*command;
}	t_commands;

typedef struct s_write
{
	struct s_commands	*head;
	struct s_commands	*tail;
}	t_write;

typedef struct s_node
{
	long			number;
	long			index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_list
{
	unsigned int	length;
	struct s_node	*head;
	struct s_node	*tail;
	long			*tab;
	long			first_mid;
	long			quarter;
	char			c;
	struct s_write	*l_co;
}	t_list;

typedef struct s_container
{
	int	n_tabs;
}	t_container;

long	ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_itoa(long n);
#endif