/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/24 19:09:16 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static char	**free_split(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

static int	size_word(char const *s, char *charset)
{
	int		count;

	count = 0;
	while (!is_charset(*s, charset) && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static int	count_words(char const *s, char *charset, t_container *container)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	container->n_tabs = 0;
	while (s[i])
	{
		while (is_charset(s[i], charset) && *s)
			i++;
		if (!is_charset(s[i], charset) && s[i])
		{
			count++;
			while (!is_charset(s[i], charset) && s[i])
				i++;
		}
	}
	container->n_tabs = count;
	return (count);
}

char	**ft_split(char const *s, char *ch, t_container *container)
{
	char	**split;
	char	*flag;
	int		nb_words;
	int		index;

	if (!s)
		return (NULL);
	flag = (char *)s;
	nb_words = count_words(s, ch, container);
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	split[nb_words] = NULL;
	index = -1;
	while (++index < nb_words)
	{
		while (is_charset(*flag, ch))
			flag++;
		split[index] = (char *)malloc(sizeof(char) * (size_word(flag, ch) + 1));
		if (!split[index])
			return (free_split(split, index));
		ft_strlcpy(split[index], flag, size_word(flag, ch) + 1);
		flag += (size_word(flag, ch) + 1);
	}
	return (split);
}

/*
#include <stdio.h>

int main (void)
{
	char **yo;
	int i;
	int j;
	char charset [] = {9, 10, 11, 12, 13, 32, 127};

	i = 0;
	j = 0;
	yo = ft_split("15 24 36 32", charset);
	while (i < 5)
	{
		printf("%s\n", yo[i]);
		i++;
	}
}
*/