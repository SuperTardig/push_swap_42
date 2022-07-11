/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:42:34 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 11:50:56 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	redirec_b(t_stacks *stacks)
{
	t_intlist	*head;

	stacks->i = 0;
	stacks->size = stacksize(stacks->stack_b, 0);
	head = stacks->stack_b;
	while (stacks->i < stacks->size)
		put_b_in_a(stacks, &head);
}

void	redirec_a(t_stacks *stacks, t_intlist *head, int var)
{
	while (stacks->i < stacks->size)
	{
		if (stacks->stack_a->index >= stacks->median_index - stacks->chunk
			&& stacks->stack_a->index <= stacks->median_index + stacks->chunk)
		{
			var = stacks->stack_a->index;
			stacks->stack_a = head;
			put_a_in_b(stacks, var);
			head = stacks->stack_a;
			stacks->size--;
			stacks->i = 0;
		}
		else
		{
			stacks->stack_a = stacks->stack_a->next;
			stacks->i++;
			if (stacks->i == stacks->size)
			{
				stacks->stack_a = head;
				stacks->i = 0;
				stacks->chunk += stacks->chunk_size;
			}
		}
	}
}

void	ten_to_infinite(t_stacks *stacks)
{
	int			var;
	t_intlist	*head;

	var = 0;
	if (stacksize(stacks->stack_a, 0) <= 100)
		stacks->chunk_size = 10;
	else
		stacks->chunk_size = 29;
	stacks->chunk = stacks->chunk_size;
	stacks->i = 0;
	stacks->size = stacksize(stacks->stack_a, 0);
	head = stacks->stack_a;
	redirec_a(stacks, head, var);
	redirec_b(stacks);
}
