/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:07:20 by bperron           #+#    #+#             */
/*   Updated: 2022/07/05 10:43:28 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	flip(t_intlist *stack, int to_find, int i)
{
	int	dir;

	if ((stacksize(*stack, 1) / 2)
		> findindice(stack, to_find))
		dir = 1;
	else
		dir = 2;
	while (stack->index != to_find)
	{
		if (dir == 2)
			rrab(stack, i);
		else
			rab(stack, i);
		if (stack)
			stack = returntop(stack);
	}
}

int	findmax(t_intlist *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
	return (max);
}

void	indexing(t_intlist *stack)
{
	int	index;
	int	min;

	index = 1;
	min = stack->content;
	stack = stack->next;
	while (index < stacksize(*stack, 0))
	{
		min = find_min_index(stack);
		stack = returntop(stack);
		while (stack->content != min)
			stack = stack->next;
		stack->index = index++;
		stack = returntop(stack);
	}
	while (stack->index != 0)
		stack = stack->next;
	stack->index = index;
}

int	find_min_index(t_intlist *stack)
{
	int	min;

	min = INT_MAX;
	stack = returntop(stack);
	while (stack->next)
	{
		if (min > stack->content && stack->index == 0)
			min = stack->content;
		stack = stack->next;
	}
	if (min > stack->content && stack->index == 0)
			min = stack->content;
	return (min);
}

void	find_median(t_stacks *stacks)
{
	int	size;

	size = stacksize(*stacks->stack_a, 0) / 2 + 1;
	while (stacks->stack_a->index != size)
		stacks->stack_a = stacks->stack_a->next;
	stacks->median = stacks->stack_a->content;
	stacks->median_index = stacks->stack_a->index;
}
