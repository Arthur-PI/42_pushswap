/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:52 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:32:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define ERROR 1
# define NO_ERROR 0

# define NOT_FOUND -1

# ifndef BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_cost
{
	int	a;
	int	b;
	int	total;
}				t_cost;

int		stack_size(t_stack *stack);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_pop_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);

void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rotate_reverse(t_stack **stack);
void	swap_both(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	rotate_reverse_both(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);

void	sb(t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rb(t_stack **b);
void	rrb(t_stack **b);

void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*parse_input(int ac, char **av);
int		error_msg(const char *s, int code);
int		is_sorted(t_stack *stack);
void	free_stacks(t_stack **a, t_stack **b);
int		closest_to_zero(int a, int b);

void	sort_big(t_stack **a, t_stack **b);
void	put_to_a(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);
t_cost	get_cost(t_stack *a, t_stack *b, int size[2], int i);
t_cost	get_min_cost(t_cost a, t_cost b);
int		get_index(t_stack *stack, int val);
int		cost_to_top(int size, int i);
void	push_top_a(t_stack **a, int cost);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);

#endif
