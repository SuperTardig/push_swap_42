/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:50:50 by bperron           #+#    #+#             */
/*   Updated: 2022/06/08 11:17:38 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "limits.h"

typedef struct s_intlist
{
	int						content;
	struct s_intlist		*next;
	struct s_intlist		*prev;
}	t_intlist;

typedef struct s_stacks
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
}	t_stacks;

int			error(int ac, char *av[]);
int			checkmax(int ac, char *av[]);
int			checkdup(int ac, char *av[]);
int			checkint(int ac, char *av[]);

long long	ft_atoll(const char *str);
int			stacksize(t_intlist stack, int j);
int			checkorder(t_intlist *stack);
t_intlist	*returntop(t_intlist *stack);
void		printstack(t_intlist *stack);
int			findindice(t_intlist *stack, int num);
void		clean(t_stacks *stacks, char ***split);
void		cleanstacks(t_stacks *stacks);
int			findmax(t_intlist *stack);
int			findmin(t_intlist *stack);
int			findmin_chunk(t_intlist *stackk, int chunk);
t_intlist	*flip(t_intlist *stack, int min, int i);

void		pushswap(t_stacks *stacks, char ***split, int ac, char *av[]);
void		redirection(t_stacks *stacks, char ***split, char *av[]);
void		sorting(t_stacks *stacks);
void		three(t_intlist *stacks);
void		four_to_nine(t_stacks *stacks, int nbsize);
void		ten_to_infinite(t_stacks *stacks);
void		align(t_intlist *stack, int min);

void		ss(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		sab(t_intlist *stack, int i);
void		rab(t_intlist *stack, int i);
void		rrab(t_intlist *stack, int i);
t_stacks	*pa_no_dst(t_stacks *stacks);
t_stacks	*pb_no_dst(t_stacks *stacks);
t_stacks	*pa_with_dst(t_stacks *stacks);
t_stacks	*pb_with_dst(t_stacks *stacks);
t_stacks	*pab(t_stacks *stacks, int i);

#endif
