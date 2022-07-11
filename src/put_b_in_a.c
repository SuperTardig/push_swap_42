/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_b_in_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:44:10 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 13:17:51 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	option_4(t_stacks **stacks, t_intlist **head)
{
	if ((*stacks)->stack_b != NULL && (*stacks)->stack_b->next != NULL
		&& ((*stacks)->stack_b->index < (*stacks)->stack_b->next->index))
	{
		ss(&(*stacks)->stack_a, &(*stacks)->stack_b);
		*head = (*stacks)->stack_b;
	}
	else
		sab(&(*stacks)->stack_a, 'a');
	(*stacks)->size--;
}

static void	option_3(t_stacks **stacks, t_intlist **head)
{
	(*stacks)->stack_b = *head;
	while ((*stacks)->stack_b->index != (*stacks)->size - 1
		|| (*stacks)->stack_b->index != (*stacks)->size)
	{
		rrab(&(*stacks)->stack_b, 'b');
		*head = (*stacks)->stack_b;
		if ((*stacks)->stack_b->index == (*stacks)->size - 1
			|| (*stacks)->stack_b->index == (*stacks)->size)
			break ;
	}
	if ((*stacks)->stack_b->index == (*stacks)->size)
	{
		pab(&(*stacks)->stack_b, &(*stacks)->stack_a, 'a');
		*head = (*stacks)->stack_b;
		if ((*stacks)->stack_a->next
			&& ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index))
			option_4(stacks, head);
		(*stacks)->size--;
	}
	else if ((*stacks)->stack_b->index == (*stacks)->size - 1)
	{
		pab(&(*stacks)->stack_b, &(*stacks)->stack_a, 'a');
		*head = (*stacks)->stack_b;
	}
	(*stacks)->i = 0;
}

static void	option_2(t_stacks **stacks, t_intlist **head)
{
	(*stacks)->stack_b = *head;
	while ((*stacks)->stack_b->index != (*stacks)->size - 1)
	{
		rab(&(*stacks)->stack_b, 'b');
		*head = (*stacks)->stack_b;
		if ((*stacks)->stack_b->index == (*stacks)->size - 1)
			break ;
	}
	if ((*stacks)->stack_b->index == (*stacks)->size - 1)
	{
		pab(&(*stacks)->stack_b, &(*stacks)->stack_a, 'a');
		*head = (*stacks)->stack_b;
		(*stacks)->i = 0;
	}
}

static void	option_1(t_stacks **stacks, t_intlist **head)
{
	(*stacks)->stack_b = *head;
	while ((*stacks)->stack_b->index != (*stacks)->size)
	{
		rab(&(*stacks)->stack_b, 'b');
		*head = (*stacks)->stack_b;
		if ((*stacks)->stack_b->index == (*stacks)->size)
			break ;
	}
	if ((*stacks)->stack_b->index == (*stacks)->size)
	{
		pab(&(*stacks)->stack_b, &(*stacks)->stack_a, 'a');
		*head = (*stacks)->stack_b;
		if ((*stacks)->stack_a->next != NULL
			&& ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index))
			option_4(stacks, head);
	(*stacks)->i = 0;
	(*stacks)->size--;
	}
}

void	put_b_in_a(t_stacks *stacks, t_intlist **head)
{
	if ((stacks->stack_b->index == stacks->size
			|| stacks->stack_b->index == stacks->size - 1)
		&& stacks->i <= stacks->size / 2)
	{
		if (stacks->stack_b->index == stacks->size)
			option_1(&stacks, head);
		else if (stacks->stack_b->index == stacks->size - 1)
			option_2(&stacks, head);
	}
	else if ((stacks->stack_b->index == stacks->size
			|| stacks->stack_b->index == stacks->size - 1)
		&& stacks->i > stacks->size / 2)
		option_3(&stacks, head);
	else
	{
		if (stacks->stack_b->next)
			stacks->stack_b = stacks->stack_b->next;
		stacks->i++;
	}
}
