/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a_in_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:43:29 by bperron           #+#    #+#             */
/*   Updated: 2022/07/12 09:41:04 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	option_3(t_stacks *stacks)
{
	if (stacks->stack_a
		&& (stacks->stack_a->index < stacks->median_index - stacks->chunk
			|| stacks->stack_a->index > stacks->median_index + stacks->chunk)
		&& stacks->stack_b->next->index > stacks->stack_b->index)
		ss(&stacks->stack_a, &stacks->stack_b);
	else if (stacks->stack_b->next->index > stacks->stack_b->index)
		sab(&stacks->stack_b, 'b');
}

static void	option_2(t_stacks *stacks, int var)
{
	int	i;

	i = -1;
	while (++i < stacksize(stacks->stack_a, 0))
	{
		if (stacks->stack_a->index == var)
		{
			pab(&stacks->stack_a, &stacks->stack_b, 'b');
			if (var < stacks->median_index
				&& stacksize(stacks->stack_b, 0) != 1)
				rab(&stacks->stack_b, 'b');
			else if (var >= stacks->median_index
				&& stacksize(stacks->stack_b, 0) > 1)
				option_3(stacks);
			break ;
		}
		else if (stacks->stack_a->next)
			rrab(&stacks->stack_a, 'a');
	}
}

static void	option_1(t_stacks *stacks, int var)
{
	int	i;

	i = -1;
	while (++i < stacksize(stacks->stack_a, 0))
	{
		if (stacks->stack_a->index == var)
		{
			pab(&stacks->stack_a, &stacks->stack_b, 'b');
			if (var < stacks->median_index
				&& stacksize(stacks->stack_b, 0) != 1)
			{
				rab(&stacks->stack_b, 'b');
			}
			else if (var >= stacks->median_index
				&& stacksize(stacks->stack_b, 0) > 1)
				option_3(stacks);
			break ;
		}
		else if (stacks->stack_a->next)
			rab(&stacks->stack_a, 'a');
	}
}

void	put_a_in_b(t_stacks *stacks, int var)
{
	if ((var < stacks->median_index
			&& stacks->i <= stacksize(stacks->stack_a, 0) / 2)
		|| (var >= stacks->median_index
			&& stacks->i <= stacksize(stacks->stack_a, 0) / 2))
		option_1(stacks, var);
	else if ((var < stacks->median_index
			&& stacks->i > stacksize(stacks->stack_a, 0) / 2)
		|| (var >= stacks->median_index
			&& stacks->i > stacksize(stacks->stack_a, 0) / 2))
		option_2(stacks, var);
}
