/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:52:53 by bperron           #+#    #+#             */
/*   Updated: 2022/06/08 11:11:28 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

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
void		quit(t_stacks *stacks, char *output);

int			sorting(t_stacks *stacks);
void		format(t_stacks *stacks, char *output);
void		pushswap(t_stacks *stacks, char ***split, int ac, char *av[]);
void		redirection(t_stacks *stacks, char ***split, char *av[]);

void		ss(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		sab(t_intlist *stack);
void		rab(t_intlist *stack);
void		rrab(t_intlist *stack);
t_stacks	*pa_no_dst(t_stacks *stacks);
t_stacks	*pb_no_dst(t_stacks *stacks);
t_stacks	*pa_with_dst(t_stacks *stacks);
t_stacks	*pb_with_dst(t_stacks *stacks);
t_stacks	*pab(t_stacks *stacks, int i);

#endif
