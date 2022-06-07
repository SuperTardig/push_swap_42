/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:53:14 by bperron           #+#    #+#             */
/*   Updated: 2022/06/07 14:49:05 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(t_stacks *stacks)
{
	sab(stacks->stack_a);
	sab(stacks->stack_b);
	ft_printf("ss\n");
}

void	rr(t_stacks *stacks)
{
	rab(stacks->stack_a);
	rab(stacks->stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	rrab(stacks->stack_a);
	rrab(stacks->stack_b);
	ft_printf("rrr\n");
}