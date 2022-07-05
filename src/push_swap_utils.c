/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:55:56 by bperron           #+#    #+#             */
/*   Updated: 2022/06/28 11:32:25 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printstack(t_intlist *stack)
{
	stack = returntop(stack);
	while (stack->next != NULL)
	{
		printf ("index = %d, number = %d\n", stack->index, stack->content);
		stack = stack->next;
	}
	printf ("index = %d, number = %d\n", stack->index, stack->content);
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
