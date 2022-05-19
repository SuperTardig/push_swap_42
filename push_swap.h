/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:50:50 by bperron           #+#    #+#             */
/*   Updated: 2022/05/19 11:01:17 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "limits.h"

typedef struct s_intlist
{
    int                 content;
    struct s_intlist    *next;
}   t_intlist;

typedef struct s_stacks
{
    t_intlist   *stack_a;
    t_intlist   *stack_b;
}   t_stacks;


int error(int ac, char *av[]);
long long	ft_atoll(const char *str);
int checkmax(int ac, char *av[]);
int checkdup(int ac, char *av[]);
int checkint(int ac, char *av[]);

#endif
