/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:50:44 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:07:02 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initstacks(t_intlist *stack_a, int count, char **integrers)
{
	t_intlist	*hold;
	int			i;

	i = 0;
	while (++i < count)
	{
		if (integrers[i] != NULL)
			stack_a->content = ft_atoi(integrers[i]);
		stack_a->index = 0;
		if (i != count - 1)
		{
			hold = stack_a;
			stack_a->next = malloc(sizeof(t_intlist));
			stack_a = stack_a->next;
		}
	}
	stack_a->next = NULL;
}

void	sorting(t_stacks *stacks)
{
	indexing(stacks->stack_a);
	if (stacksize(stacks->stack_a, 0) == 2)
	{
		if (stacks->stack_a->content > stacks->stack_a->next->content)
			sab(&stacks->stack_a, 'a');
	}
	else if (stacksize(stacks->stack_a, 0) == 3)
		three(&stacks->stack_a);
	else if (stacksize(stacks->stack_a, 0) > 3
		&& stacksize(stacks->stack_a, 0) < 10)
		four_to_nine(stacks, stacksize(stacks->stack_a, 0) - 3);
	else
	{
		find_median(stacks);
		ten_to_infinite(stacks);
	}
}

void	redirection(t_stacks *stacks, char ***split, char *av[])
{
	int	nbint;

	nbint = 0;
	*split = ft_split(av[1], ' ', &nbint);
	if (error(nbint, *split))
	{
		if (split != NULL)
			clean(NULL, split);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	if (nbint == 2)
	{
		clean(NULL, split);
		exit (0);
	}
	stacks->stack_a = malloc(sizeof(t_intlist));
	initstacks(stacks->stack_a, nbint, *split);
}

void	pushswap(t_stacks *stacks, char ***split, int ac, char *av[])
{
	if (ac == 2)
	{
		redirection(stacks, split, av);
	}
	else
	{
		if (error(ac, av) == 1)
		{
			clean(stacks, split);
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		stacks->stack_a = malloc(sizeof(t_intlist));
		initstacks(stacks->stack_a, ac, av);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	char		**split;

	split = NULL;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	pushswap(&stacks, &split, ac, av);
	if (checkorder(stacks.stack_a) == 0)
	{
		clean(&stacks, &split);
		return (0);
	}
	sorting(&stacks);
	clean(&stacks, &split);
	return (0);
}
