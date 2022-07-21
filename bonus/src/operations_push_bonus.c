/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:12:30 by bperron           #+#    #+#             */
/*   Updated: 2022/07/21 09:52:21 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_stacks	*pa_no_dst(t_stacks *stacks)
{
	if (stacks->stack_b)
	{
		stacks->stack_b = returntop(stacks->stack_b);
		stacks->stack_a = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		if (stacks->stack_b)
			stacks->stack_b->prev = NULL;
		stacks->stack_a->next = NULL;
		stacks->stack_a->prev = NULL;
	}
	return (stacks);
}

t_stacks	*pa_with_dst(t_stacks *stacks)
{
	t_intlist	*hold;

	if (stacks->stack_b)
	{
		stacks->stack_b = returntop(stacks->stack_b);
		stacks->stack_a = returntop(stacks->stack_a);
		if (stacksize(*stacks->stack_b, 0) > 0)
		{
			hold = stacks->stack_b;
			stacks->stack_b = stacks->stack_b->next;
			if (stacks->stack_b)
				stacks->stack_b->prev = NULL;
			stacks->stack_a->prev = hold;
			hold = stacks->stack_a;
			stacks->stack_a = stacks->stack_a->prev;
			stacks->stack_a->prev = NULL;
			stacks->stack_a->next = hold;
		}
	}
	return (stacks);
}

t_stacks	*pb_no_dst(t_stacks *stacks)
{
	if (stacks->stack_a)
	{
		stacks->stack_a = returntop(stacks->stack_a);
		stacks->stack_b = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		if (stacks->stack_a)
			stacks->stack_a->prev = NULL;
		stacks->stack_b->next = NULL;
		stacks->stack_b->prev = NULL;
	}
	return (stacks);
}

t_stacks	*pb_with_dst(t_stacks *stacks)
{
	t_intlist	*hold;

	if (stacks->stack_a)
	{
		stacks->stack_a = returntop(stacks->stack_a);
		stacks->stack_b = returntop(stacks->stack_b);
		if (stacksize(*stacks->stack_a, 0) > 0)
		{
			hold = stacks->stack_a;
			stacks->stack_a = stacks->stack_a->next;
			if (stacks->stack_a)
				stacks->stack_a->prev = NULL;
			stacks->stack_b->prev = hold;
			hold = stacks->stack_b;
			stacks->stack_b = stacks->stack_b->prev;
			stacks->stack_b->prev = NULL;
			stacks->stack_b->next = hold;
		}
	}
	return (stacks);
}
