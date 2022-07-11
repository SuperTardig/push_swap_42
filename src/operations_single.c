/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:38:56 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:51:10 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sab(t_intlist **stack, char c)
{
	t_intlist	*head;
	t_intlist	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = head;
	head->next = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rab(t_intlist **stack, char c)
{
	t_intlist	*head;
	t_intlist	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	temp = *stack;
	*stack = (*stack)->next;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			temp->next = head;
			head->next = NULL;
		}
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rrab(t_intlist **stack, char c)
{
	t_intlist	*head;
	t_intlist	*temp;

	head = *stack;
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	temp->next = NULL;
	head->next = *stack;
	*stack = head;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	pab(t_intlist **from, t_intlist **to, char c)
{
	t_intlist	*temp;

	temp = *from;
	if (!(*from))
		return ;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
