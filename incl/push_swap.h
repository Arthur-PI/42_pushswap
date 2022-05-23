/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:52 by apigeon           #+#    #+#             */
/*   Updated: 2022/05/23 10:24:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>


typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

// temporary debbug function
void	print_stacks(t_stack *a, t_stack *b);

t_stack	*stack_new(int value);
int	stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_pop_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);

void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rotate_reverse(t_stack **stack);

void    sa(t_stack  **a);
void    pa(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rra(t_stack **a);

void    sb(t_stack  **b);
void    pb(t_stack **b, t_stack **a);
void    rb(t_stack **b);
void    rrb(t_stack **b);

void    ss(t_stack  **a, t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rrr(t_stack **a, t_stack **b);

t_stack	*parse_input(int ac, char **av);


#endif
