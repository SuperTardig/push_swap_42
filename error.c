/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:42:48 by bperron           #+#    #+#             */
/*   Updated: 2022/05/19 11:21:40 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long long	ft_atoll(const char *str)
{
	int			i;
	long long		signe;
	long long		nb;

	signe = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * signe);
}

int checkmax(int ac, char *av[])
{
    long long j;
    int i;

    i = 1;
    while (i < ac)
    {
        j = ft_atoll(av[i]);
        if (j > INT_MAX || j < INT_MIN)
            return (1);
        i++;
    }
    return (0);
}

int checkdup(int ac, char *av[])
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = 0;
        while (j++ < ac - 1)
            if(i != j)
                if (ft_strcmp(av[i], av[j]) == 0)
                    return (1);
        i++;
    }
    return (0);
}

int checkint(int ac, char *av[])
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int error(int ac, char *av[])
{
    if (checkmax(ac, av) == 1 || checkdup(ac, av) == 1
    || checkint(ac, av) == 1)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    return (0);
}
