/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:07:20 by bperron           #+#    #+#             */
/*   Updated: 2022/06/07 10:09:49 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*flip(t_intlist *stack, int min, int i)
{
	while (stack->content != min)
	{
		if ((stacksize(*stack, 1) / 2)
			>= findindice(stack, min))
			rab(stack, i);
		else
			rrab(stack, i);
		stack = returntop(stack);
	}
	return (stack);
}

int	findmax(t_intlist *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
	return (max);
}
