/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/10 17:00:20 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	int				i;
	char			*tmp;
	static char		*after_newline;
	int				ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
	{
		if (after_newline)
			free(after_newline);
		return (-1);
	}
	if (!after_newline)
		after_newline = ft_strdup("");
	while (!(ft_strchr(after_newline, '\n') && ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret == 0)
		{
			*line = ft_strdup(after_newline);
			free(after_newline);
			after_newline = NULL;
			return (0);
		}
		after_newline = ft_strjoin(after_newline, buffer);
	}
	i = 0;
	tmp = after_newline;
	while (tmp && *tmp++ != '\n')
		i++;
	*line = ft_strndup(after_newline, i);
	tmp = ft_strdup(tmp);
	free(after_newline);
	after_newline = tmp;
	return (1);
}
