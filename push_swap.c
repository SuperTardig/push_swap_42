/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:50:44 by bperron           #+#    #+#             */
/*   Updated: 2022/05/19 11:13:18 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    initstacks(t_intlist *stack_a, int count, char **integrers)
{
    int i;

    i = 0;
    while (++i < count)
    {
        stack_a->content = ft_atoi(integrers[i]);
        if (i != count)
        {
            stack_a->next = malloc(sizeof(t_intlist));
            stack_a = stack_a->next;
        }
    }
    stack_a->next = NULL;
}

int checkorder(t_intlist *stack)
{
    int i;
    int j;

    while (stack->next != NULL)
    {
        i = (int) stack->content;
        stack = stack->next;
        if (stack->next != NULL)
            j = (int) stack->content;
        else
            break;
        if (i > j)
            return (1);
    }
    return (0);
}

int main(int ac, char *av[])
{
    t_stacks    stacks;
    char        **split;
    int         nbint;

    stacks.stack_a = malloc(sizeof(t_intlist));
    if (ac == 2)
    {
        nbint = 0;
        split = ft_split(av[1], ' ', &nbint);
        if (error(nbint, split) == 1)
            return (1);
        initstacks(stacks.stack_a, nbint, split);
    }
    else
    {
        initstacks(stacks.stack_a, ac, av);
        if (error(ac, av) == 1 || ac < 2)
            return (1);
    }
    if (checkorder(stacks.stack_a) == 1)
        return (0);
    //sorting(stacks);
}
