/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:46:35 by bperron           #+#    #+#             */
/*   Updated: 2022/07/18 10:58:32 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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

int	sorting(t_stacks *stacks)
{
	char	*output;
	int		nbmove;

	nbmove = 0;
	output = get_next_line(0);
	while (output)
	{
		format(stacks, output);
		free(output);
		nbmove++;
		output = get_next_line(0);
	}
	free(output);
	return (nbmove);
}

void	redirection(t_stacks *stacks, char ***split, char *av[])
{
	int	nbint;

	nbint = 0;
	*split = ft_split(av[1], ' ', &nbint);
	if (error(nbint, *split) || nbint < 2)
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
	clean(NULL, split);
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
		clean(NULL, split);
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	char		**split;

	split = NULL;
	if (ac == 1)
		return (0);
	pushswap(&stacks, &split, ac, av);
	ft_printf("%d move done\n", sorting(&stacks));
	if (checkorder(stacks.stack_a) == 0 && !(stacks.stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean(&stacks, NULL);
	return (0);
}
