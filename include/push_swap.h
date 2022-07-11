/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:50:50 by bperron           #+#    #+#             */
/*   Updated: 2022/07/11 14:04:03 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_intlist
{
	int						content;
	int						index;
	struct s_intlist		*next;
}	t_intlist;

typedef struct s_stacks
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	int			median_index;
	int			i;
	int			size;
	int			chunk;
	int			chunk_size;
}	t_stacks;

int			error(int ac, char *av[]);
int			checkmax(int ac, char *av[]);
int			checkdup(int ac, char *av[]);
int			checkint(int ac, char *av[]);

long long	ft_atoll(const char *str);
int			stacksize(t_intlist *stack, int j);
int			checkorder(t_intlist *stack);
void		printstack(t_intlist *stack);
int			findindice(t_intlist *stack, int num);
void		clean(t_stacks *stacks, char ***split);
void		cleanstacks(t_stacks *stacks);
int			findmax(t_intlist *stack);
int			findmin(t_intlist *stack);
int			findmin_chunk(t_intlist *stackk, int chunk);
void		flip(t_intlist **stack, int min);
void		indexing(t_intlist *stack);
int			find_min_index(t_intlist *stack);
void		find_median(t_stacks *stacks);

void		pushswap(t_stacks *stacks, char ***split, int ac, char *av[]);
void		redirection(t_stacks *stacks, char ***split, char *av[]);
void		sorting(t_stacks *stacks);
void		three(t_intlist **stacks);
void		four_to_nine(t_stacks *stacks, int nbsize);
void		ten_to_infinite(t_stacks *stacks);
void		put_a_in_b(t_stacks *stacks, int var);
void		put_b_in_a(t_stacks *stacks, t_intlist **head);

void		sab(t_intlist **stack, char c);
void		rab(t_intlist **stack, char c);
void		rrab(t_intlist **stack, char c);
void		pab(t_intlist **s1, t_intlist **s2, char c);
void		ss(t_intlist **a, t_intlist **b);
void		rr(t_stacks *stacks);
void		rrr(t_stacks *stacks);

#endif
