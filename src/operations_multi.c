/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:53:14 by bperron           #+#    #+#             */
/*   Updated: 2022/06/08 10:16:09 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stacks *stacks)
{
	sab(stacks->stack_a, 0);
	sab(stacks->stack_b, 0);
	ft_printf("ss\n");
}

void	rr(t_stacks *stacks)
{
	rab(stacks->stack_a, 0);
	rab(stacks->stack_b, 0);
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	rrab(stacks->stack_a, 0);
	rrab(stacks->stack_b, 0);
	ft_printf("rrr\n");
}
