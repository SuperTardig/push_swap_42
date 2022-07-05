/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:42:34 by bperron           #+#    #+#             */
/*   Updated: 2022/07/05 13:37:35 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_next(t_stacks stacks, int chunk, int *i)
{
	if (stacks.stack_a)
	{
		while (stacks.stack_a->next != NULL)
		{
			if (stacks.stack_a->index >= stacks.median_index - chunk
				&& stacks.stack_a->index <= stacks.median_index + chunk)
				return (stacks.stack_a->index);
			stacks.stack_a = stacks.stack_a->next;
			*i += 1;
		}
	}
	return (0);
}

int	find_next(t_stacks stacks, int chunk)
{
	int	next;
	int	next2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	next = check_next(stacks, chunk, &i);
	if (stacks.stack_a)
	{
		while (stacks.stack_a->next != NULL)
			stacks.stack_a = stacks.stack_a->next;
		while (stacks.stack_a->prev != NULL)
		{
			if (stacks.stack_a->index >= stacks.median_index - chunk
				&& stacks.stack_a->index <= stacks.median_index + chunk)
			{
				next2 = stacks.stack_a->index;
				break ;
			}
			stacks.stack_a = stacks.stack_a->prev;
			j++;
		}
	}
	if (i <= j)
		return (next);
	else
		return (next2);
}


int	find_next2(t_intlist *stack, int *which)
{
	int	max;
	int	i;
	int	j;

	max = findmax(stack);
	i = 0;
	j = 0;
	while (stack->index != max)
	{
		i++;
		stack = stack->next;
	}
	stack = returntop(stack);
	if (stacksize(*stack, 0) >= 2)
	{
		while (stack->index != max - 1)
		{
			j++;
			if (stack->next)
			stack = stack->next;
		}
	}
	if (i < j)
	{
		*which = 1;
		return (max);
	}
	else
	{
		*which = 2;
		return (max - 1);
	}
}

void	put_b_in_a(t_stacks *stacks)
{
	int	which;
	int	next;

	while (stacks->stack_b)
	{
		stacks->stack_b = returntop(stacks->stack_b);
		next = find_next2(stacks->stack_b, &which);
		if (which == 2)
		{
			flip(stacks->stack_b, next, 2);
			pab(stacks, 2);
			flip(stacks->stack_b, next + 1, 2);
			pab(stacks, 2);
			sab(stacks->stack_a, 1);
		}
		else
		{
			flip(stacks->stack_b, next, 2);
			pab(stacks, 2);
			if (stacksize(*stacks->stack_a, 0) >= 1)
			{
				flip(stacks->stack_b, next - 1, 2);
				pab(stacks, 2);
			}
		}
	}
}
// indexation est bad je pense

void	ten_to_infinite(t_stacks *stacks)
{
	int	chunk;
	int	temp;
	int	next;
	int	i;
	int	size;

	if (stacksize(*stacks->stack_a, 0) <= 100)
		temp = 10;
	else
		temp = 33;
	chunk = temp;
	i = 0;
	stacks->stack_a = returntop(stacks->stack_a);
	size = stacksize(*stacks->stack_a, 0);
	while (++i <= size)
	{
		if (i == (chunk * 2) + 1)
			chunk += temp;
		next = find_next(*stacks, chunk);
		if (stacksize(*stacks->stack_a, 0) > 1)
			flip(stacks->stack_a, next, 1);
		stacks->stack_a = returntop(stacks->stack_a);
		if (next <= stacks->median_index)
		{
			pab(stacks, 1);
			if (stacksize(*stacks->stack_b, 0) > 1)
				rab(stacks->stack_b, 2);
		}
		else
			pab(stacks, 1);
		if (stacks->stack_a)
			stacks->stack_a = returntop(stacks->stack_a);
	}
	put_b_in_a(stacks);
}

int	check_ss(t_stacks stacks, int chunk)
{
	int	i;

	i = 0;
	if (stacksize(*stacks.stack_b, 0) > 1)
		if (stacks.stack_b->index < stacks.stack_b->next->index)
			i += 2;
	if (stacksize(*stacks.stack_a, 0) > 1)
		if ((stacks.stack_a->index <= stacks.median_index - chunk
				&& stacks.stack_a->index >= stacks.median_index + chunk)
			&& (stacks.stack_a->next->index >= stacks.median_index - chunk
				&& stacks.stack_a->next->index <= stacks.median_index + chunk))
			i++;
	return (i);
}

int	check_rr(t_stacks stacks, int chunk)
{
	int	i;

	i = 0;
	if (stacksize(*stacks.stack_a, 0) > 1)
		if ((stacks.stack_a->index <= stacks.median_index - chunk
				&& stacks.stack_a->index >= stacks.median_index + chunk)
			&& ((stacks.stack_a->next->index >= stacks.median_index - chunk
					&& stacks.stack_a->next->index
					<= stacks.median_index + chunk)
				|| (stacks.stack_a->next->next->index
					>= stacks.median_index - chunk
					&& stacks.stack_a->next->next->index
					<= stacks.median_index + chunk)))
			i++;
	return (i);
}
