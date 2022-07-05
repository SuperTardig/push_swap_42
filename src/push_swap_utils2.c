/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:53:23 by bperron           #+#    #+#             */
/*   Updated: 2022/07/05 08:47:40 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	findindice(t_intlist *stack, int num)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		if (stack->index == num)
			return (i);
		stack = stack->next;
	}
	return (i);
}

void	clean(t_stacks *stacks, char ***split)
{
	int			i;

	i = 1;
	cleanstacks(stacks);
	if (split)
	{
		if (*split)
		{
			while (split[0][i])
			{
				free(split[0][i]);
				i++;
			}
			free(*split);
		}
	}
}

void	cleanstacks(t_stacks *stacks)
{
	t_intlist	*tmp;

	if (stacks)
	{
		if (stacks->stack_a)
		{
			stacks->stack_a = returntop(stacks->stack_a);
			while (stacks->stack_a)
			{
				tmp = stacks->stack_a->next;
				free(stacks->stack_a);
				stacks->stack_a = tmp;
			}
		}
		if (stacks->stack_b)
		{
			while (stacks->stack_b)
			{
				tmp = stacks->stack_b->next;
				free(stacks->stack_b);
				stacks->stack_b = tmp;
			}
		}
	}
}

int	findmin(t_intlist *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
	stack = returntop(stack);
	return (min);
}

int	findmin_chunk(t_intlist *stack, int chunk)
{
	int			min;
	t_intlist	*hold;

	hold = stack;
	min = stack->content;
	while (stack)
	{
		if (min > stack->content && ((findindice(hold, stack->content)
					<= (chunk / 2)) || (findindice(hold, stack->content)
					> (stacksize(*hold, 0) - (chunk / 2)))))
			min = stack->content;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
	return (min);
}
