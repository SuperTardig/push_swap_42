/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_single_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:38:56 by bperron           #+#    #+#             */
/*   Updated: 2022/07/12 11:38:54 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_stacks	*pab(t_stacks *stacks, int i)
{
	if (i == 1)
	{
		if (!(stacks->stack_b))
			pb_no_dst(stacks);
		else
			pb_with_dst(stacks);
	}
	else if (i == 2)
	{
		if (!(stacks->stack_a))
			pa_no_dst(stacks);
		else
			pa_with_dst(stacks);
	}
	return (stacks);
}

void	sab(t_intlist *stack)
{
	t_intlist	*hold;
	t_intlist	*temp;

	if (stack)
	{
		stack = returntop(stack);
		if (stacksize(*stack, 0) > 1)
		{
			hold = stack;
			stack->prev = stack->next;
			stack = stack->next;
			stack->prev = NULL;
			temp = stack->next;
			stack->next = hold;
			stack = stack->next;
			stack->next = temp;
			if (stack->next)
				stack->next->prev = stack;
		}
	}
}

void	rab(t_intlist *stack)
{
	t_intlist	*hold;

	if (stack)
	{
		if (stacksize(*stack, 0) > 1)
		{
			hold = stack;
			stack = stack->next;
			stack->prev = NULL;
			while (stack->next)
				stack = stack->next;
			stack->next = hold;
			hold = stack;
			stack = stack->next;
			stack->prev = hold;
			stack->next = NULL;
		}
	}
}

void	rrab(t_intlist *stack)
{
	t_intlist	*hold;

	if (stack)
	{
		if (stacksize(*stack, 0) > 1)
		{
			stack = returntop(stack);
			while (stack->next != NULL)
				stack = stack->next;
			hold = stack;
			stack = stack->prev;
			stack->next = NULL;
			while (stack->prev != NULL)
				stack = stack->prev;
			stack->prev = hold;
			hold = stack;
			stack = stack->prev;
			stack->next = hold;
			stack->prev = NULL;
		}
	}
}
