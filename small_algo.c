/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:41:32 by bperron           #+#    #+#             */
/*   Updated: 2022/06/07 09:33:17 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_intlist *stack)
{
	if (stack->content < stack->next->content)
		rrab(stack, 1);
	if (stack->content > stack->next->content
		&& stack->content > stack->next->next->content)
		rab(stack, 1);
	stack = returntop(stack);
	if (stack->content > stack->next->content
		&& stack->next->content < stack->next->next->content)
		sab(stack, 1);
	stack = returntop(stack);
}

void	four_to_nine(t_stacks *stacks, int nbsize)
{
	int	min;

	while (--nbsize >= 0)
	{
		min = findmin(stacks->stack_a);
		stacks->stack_a = flip(stacks->stack_a, min, 1);
		stacks = pab (stacks, 1);
		if (checkorder(stacks->stack_a) == 0
			&& stacksize(*stacks->stack_b, 0) == 0)
			return ;
		if (nbsize == 0 && checkorder(stacks->stack_a) != 0)
			three(stacks->stack_a);
		stacks->stack_a = returntop(stacks->stack_a);
	}
	while (stacks->stack_b->next != NULL)
		stacks = pab(stacks, 2);
	stacks = pab(stacks, 2);
}
