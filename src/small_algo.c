/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:41:32 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:51:26 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three(t_intlist **stack)
{
	if ((*stack)->content < (*stack)->next->content)
		rrab(stack, 'a');
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		rab(stack, 'a');
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content)
		sab(stack, 'a');
}

void	flip(t_intlist **stack, int min)
{
	if (findindice(*stack, min) <= stacksize(*stack, 0) / 2)
		while ((*stack)->index != min)
			rab(stack, 'a');
	else
		while ((*stack)->index != min)
			rrab(stack, 'a');
}

void	four_to_nine(t_stacks *stacks, int nbsize)
{
	int	min;

	while (--nbsize >= 0)
	{
		min = findmin(stacks->stack_a);
		flip(&stacks->stack_a, min);
		pab (&stacks->stack_a, &stacks->stack_b, 'b');
	}
	three(&stacks->stack_a);
	while (stacks->stack_b)
		pab(&stacks->stack_b, &stacks->stack_a, 'a');
}
