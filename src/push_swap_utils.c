/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:55:56 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:47:46 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printstack(t_intlist *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			printf ("index = %d, number = %d\n", stack->index, stack->content);
			stack = stack->next;
		}
		printf ("index = %d, number = %d\n", stack->index, stack->content);
	}
}

int	stacksize(t_intlist *stack, int j)
{
	int	i;

	i = 1;
	if (stack == NULL)
		return (0);
	stack = stack->next;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	if (j == 1 && i % 2 != 0)
		return (++i);
	return (i);
}

int	checkorder(t_intlist *stack)
{
	t_intlist	*head;

	head = stack;
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content >= stack->next->content)
			{
				stack = head;
				return (1);
			}
			stack = stack->next;
		}
		stack = head;
	}
	return (0);
}
