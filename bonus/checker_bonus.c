/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:46:35 by bperron           #+#    #+#             */
/*   Updated: 2022/06/07 13:21:48 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	initstacks(t_intlist *stack_a, int count, char **integrers)
{
	t_intlist	*hold;
	int			i;

	i = 0;
	stack_a->prev = NULL;
	while (++i < count)
	{
		if (integrers[i] != NULL)
			stack_a->content = ft_atoi(integrers[i]);
		if (i != count - 1)
		{
			hold = stack_a;
			stack_a->next = malloc(sizeof(t_intlist));
			stack_a = stack_a->next;
			stack_a->prev = hold;
		}
	}
	stack_a->next = NULL;
}

void	sorting(t_stacks *stacks)
{
	char	*output;

	output = get_next_line(0);
	while (output)
	{
		format(stacks, output);
		free(output);
		output = get_next_line(0);
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
	pushswap(&stacks, &split, ac, av);
	if (checkorder(stacks.stack_a) == 0)
	{
		clean(&stacks, &split);
		return (0);
	}
	sorting(&stacks);
	if (checkorder(stacks.stack_a) == 0 && stacksize(*stacks.stack_b, 0) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean(&stacks, &split);
	return (0);
}