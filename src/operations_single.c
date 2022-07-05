/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:38:56 by bperron           #+#    #+#             */
/*   Updated: 2022/06/29 09:51:27 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	*pab(t_stacks *stacks, int i)
{
	if (i == 1)
	{
		if (!(stacks->stack_b))
			pb_no_dst(stacks);
		else
			pb_with_dst(stacks);
		ft_printf("pb\n");
	}
	else if (i == 2)
	{
		if (!(stacks->stack_a))
			pa_no_dst(stacks);
		else
			pa_with_dst(stacks);
		ft_printf("pa\n");
	}
	return (stacks);
}

void	sab(t_intlist *stack, int i)
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
	if (i == 1)
		ft_printf("sa\n");
	else if (i == 2)
		ft_printf("sb\n");
}

void	rab(t_intlist *stack, int i)
{
	t_intlist	*hold;

	if (stack)
	{
		if (stacksize(*stack, 0) != 0)
		{
			stack = returntop(stack);
			hold = stack;
			stack = stack->next;
			if (stack->prev)
				stack->prev = NULL;
			while (stack->next != NULL)
				stack = stack->next;
			stack->next = hold;
			hold = stack;
			stack = stack->next;
			stack->next = NULL;
			stack->prev = hold;
		}
	}
	if (i == 1)
		ft_printf("ra\n");
	else if (i == 2)
		ft_printf("rb\n");
}

void	rrab(t_intlist *stack, int i)
{
	t_intlist	*hold;

	if (stack)
	{
		if (stacksize(*stack, 0) != 0)
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
	if (i == 1)
		ft_printf("rra\n");
	else if (i == 2)
		ft_printf("rrb\n");
}
