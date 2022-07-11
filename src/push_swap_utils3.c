/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:07:20 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:47:01 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	int			index;
	int			min;
	t_intlist	*head;

	index = 1;
	head = stack;
	while (index < stacksize(stack, 0))
	{
		min = find_min_index(stack);
		stack = head;
		while (stack->content != min)
			stack = stack->next;
		stack->index = index++;
		stack = head;
	}
	while (stack->index != 0)
		stack = stack->next;
	stack->index = index;
	stack = head;
}

int	find_min_index(t_intlist *stack)
{
	int	min;

	min = INT_MAX;
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
	int			size;
	t_intlist	*head;

	head = stacks->stack_a;
	size = stacksize(stacks->stack_a, 0) / 2 + 1;
	while (stacks->stack_a->index != size)
		stacks->stack_a = stacks->stack_a->next;
	stacks->median_index = stacks->stack_a->index;
	stacks->stack_a = head;
}
