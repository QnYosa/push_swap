/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:51:07 by dyoula            #+#    #+#             */
/*   Updated: 2021/09/24 23:40:45 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	if (dest == NULL)
		i = 0;
	//printf("%d", i);
	j = -1;
	while (src[++j])
		dest[i + j] = src[j];
	//printf("%s\n", dest);
	dest[i + j + 1] = '\0';
	return (dest);
}

char	*strjoin_double_tab(char *tmp, char **d_tab, t_container *n_argus)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(tmp) + ft_strlen(d_tab[i]); // ok
	//printf("%d\n", size);
	while (i < n_argus->n_tabs)
	{
		tmp = malloc(size + 2);
		tmp = ft_strcat(tmp, d_tab[i]);
		i++;
	}
	printf("%s\n", tmp);
	return (tmp);
}