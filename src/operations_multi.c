/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:53:14 by bperron           #+#    #+#             */
/*   Updated: 2022/06/28 09:39:51 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stacks *stacks)
{
	stacks->stack_a = returntop(stacks->stack_a);
	stacks->stack_b = returntop(stacks->stack_b);
	sab(stacks->stack_a, 0);
	sab(stacks->stack_b, 0);
	ft_printf("ss\n");
}

void	rr(t_stacks *stacks)
{
	stacks->stack_a = returntop(stacks->stack_a);
	stacks->stack_b = returntop(stacks->stack_b);
	rab(stacks->stack_a, 0);
	rab(stacks->stack_b, 0);
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	stacks->stack_a = returntop(stacks->stack_a);
	stacks->stack_b = returntop(stacks->stack_b);
	rrab(stacks->stack_a, 0);
	rrab(stacks->stack_b, 0);
	ft_printf("rrr\n");
}
