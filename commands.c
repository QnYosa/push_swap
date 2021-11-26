/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:32:56 by dyoula            #+#    #+#             */
/*   Updated: 2021/11/26 19:29:42 by dyoula           ###   ########.fr       */
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

t_write	*add_commands_start(t_write *write_, char *content)
{
	t_commands	*new_command;

	if (!write_)
		return (NULL);
	new_command = malloc(sizeof(t_commands));
	if (!new_command)
		return (NULL);
	new_command->command = content;
	new_command->next = NULL;
	if (write_->tail == NULL)
	{
		new_command->previous = NULL;
		write_->head = new_command;
		write_->tail = new_command;
	}
	else
	{
		write_->tail->next = new_command;
		new_command->previous = write_->tail;
		write_->tail = new_command;
	}
	return (write_);
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

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	delete_c(t_commands **s1, t_commands**s2)
{
	if (!*s1 || !*s2)
		return (0);
	if (compare((*s1)->command, "sa\n") == 1 \
		&& compare((*s2)->command, "sa\n") == 1)
		return (1);
	else if (compare((*s1)->command, "sb\n") == 1 \
		&& compare((*s2)->command, "sb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rb\n") == 1 \
		&& compare((*s2)->command, "rrb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rrb\n") == 1 \
		&& compare((*s2)->command, "rb\n") == 1)
		return (1);
	else if (compare((*s1)->command, "ra\n") == 1 \
		&& compare((*s2)->command, "rra\n") == 1)
		return (1);
	else if (compare((*s1)->command, "rra\n") == 1 \
		&& compare((*s2)->command, "ra\n") == 1)
		return (1);
	return (0);
}

int	optimizer(t_commands **s1, t_commands *s2)
{
	if (!*s1 || !s2)
		return (0);
	if (compare((*s1)->command, "ra\n") == 1 && compare(s2->command, "rb\n") == 1)
	{
		(*s1)->command = "rr\n";
		return (1);
	}
	else if (compare((*s1)->command, "rb\n") == 1 && compare(s2->command, "ra\n") == 1)
	{
		(*s1)->command = "rr\n";
		return (1);
	}
	else if (compare((*s1)->command, "rra\n") == 1 && compare(s2->command, "rrb\n") == 1)
	{
		(*s1)->command = "rrr\n";
		return (1);
	}
	else if (compare((*s1)->command, "rrb\n") == 1 && compare(s2->command, "rra\n") == 1)
	{
		(*s1)->command = "rrr\n";
		return (1);
	}
	else if (compare((*s1)->command, "sa\n") == 1 && compare(s2->command, "sb\n"))
	{
		(*s1)->command = "ss\n";
		return (1);
	}
	else if (compare((*s1)->command, "sb\n") == 1 && compare(s2->command, "sa\n"))
	{
		(*s1)->command = "ss\n";
		return (1);
	}
	return (0);
}

int	rotate_b_killer(t_commands **s1)
{
	t_commands	*i;

	i = (*s1);
	if (!compare((*s1)->command, "rb\n"))
		return (0);
	while (compare(i->command, "rb\n") && i->next)
		i = i->next;
	if (compare(i->command, "rrb\n") && i->next)
	{
		return (1);
	}
	return (0);
}

int	rotate_rb_killer(t_commands **s1)
{
	t_commands	*i;

	i = (*s1);
	if (!compare((*s1)->command, "rrb\n"))
		return (0);
	while (compare(i->command, "rrb\n") && i->next)
		i = i->next;
	if (compare(i->command, "rb\n") && i->next)
	{
		return (1);
	}
	return (0);
}

int	rotate_a_killer(t_commands **s1)
{
	t_commands	*i;

	i = (*s1);
	if (!compare((*s1)->command, "rra\n"))
		return (0);
	while (compare(i->command, "rra\n") && i->next)
		i = i->next;
	if (compare(i->command, "ra\n") && i->next)
	{
		return (1);
	}
	return (0);
}

int	rotate_ra_killer(t_commands **s1)
{
	t_commands	*i;

	i = (*s1);
	if (!compare((*s1)->command, "ra\n"))
		return (0);
	while (compare(i->command, "ra\n") && i->next)
		i = i->next;
	if (compare(i->command, "rra\n") && i->next)
	{
		return (1);
	}
	return (0);
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
			del = i->next;
			i->next = del->next;
			del->next->previous = i;
			free(del);
		}
		i = i->next;
	}
}
