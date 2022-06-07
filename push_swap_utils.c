/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:55:56 by bperron           #+#    #+#             */
/*   Updated: 2022/06/02 11:55:18 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			i;
	long long	signe;
	long long	nb;

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

void	printstack(t_intlist *stack)
{
	stack = returntop(stack);
	while (stack->next != NULL)
	{
		ft_printf ("%d\n", stack->content);
		stack = stack->next;
	}
	ft_printf ("%d\n", stack->content);
}

t_intlist	*returntop(t_intlist *stack)
{
	while (stack->prev != NULL)
		stack = stack->prev;
	return (stack);
}

int	stacksize(t_intlist stack, int j)
{
	int	i;

	i = 0;
	while (stack.next != NULL)
	{
		stack = *stack.next;
		i++;
	}
	i++;
	if (j == 1 && i % 2 != 0)
		return (++i);
	return (i);
}

int	checkorder(t_intlist *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content >= stack->next->content)
			{
				returntop(stack);
				return (1);
			}
			stack = stack->next;
		}
		returntop(stack);
	}
	return (0);
}
