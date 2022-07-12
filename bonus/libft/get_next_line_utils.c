/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:21 by bperron           #+#    #+#             */
/*   Updated: 2022/07/12 10:17:46 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	ft_strchri(const char *s, int c)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *) s;
	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	while (len-- > 0)
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

int	check(char *new)
{
	if (ft_strcmp(new, "sa\n") == 0 || ft_strcmp(new, "sb\n") == 0
		|| ft_strcmp(new, "ra\n") == 0 || ft_strcmp(new, "rb\n") == 0
		|| ft_strcmp(new, "rra\n") == 0 || ft_strcmp(new, "rrb\n") == 0
		|| ft_strcmp(new, "pa\n") == 0 || ft_strcmp(new, "pb\n") == 0
		|| new == NULL || ft_strcmp(new, "ss\n") == 0
		|| ft_strcmp(new, "rr\n") == 0 || ft_strcmp(new, "rrr\n") == 0)
		return (0);
	else
		return (1);
}

char	*create_stat(char *stat)
{
	stat = ft_calloc(1, 1);
	if (!stat)
		return (NULL);
	return (stat);
}
