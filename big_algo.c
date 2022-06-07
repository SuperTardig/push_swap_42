/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:42:34 by bperron           #+#    #+#             */
/*   Updated: 2022/06/07 13:01:42 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align(t_intlist *stack, int min)
{
	int	slot;

	slot = findmin(stack);
	if (min < slot)
		slot = findmax(stack);
	else
	{
		while (stack)
		{
			if (stack->content < min && stack->content > slot)
				slot = stack->content;
			if (stack->next != NULL)
				stack = stack->next;
			else
				break ;
		}
	}
	stack = returntop(stack);
	stack = flip(stack, slot, 2);
}

void	ten_to_infinite(t_stacks *stacks)
{
	int	chunk;
	int	min;

	chunk = (stacksize(*stacks->stack_a, 0) / 22) + 5;
	if ((chunk % 2) != 0)
		chunk++;
	while (stacksize(*stacks->stack_a, 0) > 1)
	{
		min = findmin_chunk(stacks->stack_a, chunk);
		stacks->stack_a = flip(stacks->stack_a, min, 1);
		if (stacks->stack_b)
			if (stacksize(*stacks->stack_b, 0) >= 2)
				align(stacks->stack_b, min);
		pab(stacks, 1);
	}
	while (stacksize(*stacks->stack_b, 0) != 1)
		pab(stacks, 2);
	pab(stacks, 2);
}
