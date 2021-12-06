/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:32:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/06 00:32:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

t_write	*init_write(void)
{
	t_write	*write;

	write = (t_write *)malloc(sizeof(t_write));
	if (!write)
		return (NULL);
	write->head = NULL;
	write->tail = NULL;
	return (write);
}

void	add_commands_start(t_write *write_, char *content)
{
	t_commands	*new_command;

	if (!write_ || !content)
		return ;
	new_command = malloc(sizeof(t_commands));
	if (!new_command)
		return ;
	new_command->command = content;
	new_command->previous = NULL;
	if (write_->tail == NULL)
	{
		new_command->next = NULL;
		write_->head = new_command;
		write_->tail = new_command;
	}
	else
	{
		write_->tail->next = new_command;
		new_command->previous = write_->tail;
		write_->tail = new_command;
	}
}

void	display_commands(t_write *l)
{
	t_commands	*tmp;

	tmp = l->head;
	while (tmp)
	{
		ft_putstr_fd(tmp->command, 1);
		tmp = tmp->next;
	}
}

long	compare(char *s1, char *s2)
{
	long	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

long	comp_max(char *s1, char *s2)
{
	long	i;

	i = 0;
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (s1[i] == s2[i])
		{
			if (i == (long)ft_strlen(s2))
				return (0);
			i++;
		}
	}
	return (1);
}

void	delete_useless(t_write **l)
{
	t_commands	*i;
	t_commands	*del;

	i = (*l)->head;
	if (!l)
		return ;
	while (i)
	{
		if (optimizer(&i, i->next))
		{
			del = i->next;
			i->next = del->next;
			del->next->previous = i;
			free(del);
		}
		if (delete_c(&i, &i->next))
		{
			del = i;
			del->previous->next = del->next;
			del->next->previous = del->previous;
			i = del->previous;
			del = del->next;
			del->previous->next = del->next;
			del->next->previous = del->previous;
			free(del);
		}
		if (rotate_b_killer(&i) || rotate_a_killer(&i) || rotate_ra_killer(&i) || rotate_rb_killer(&i))
		{
			del = i;
			i = i->previous;
			i->next = del->next;
			del->next->previous = i;
			free(del);
		}
		i = i->next;
	}
}
