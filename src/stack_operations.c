/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:51:02 by apigeon           #+#    #+#             */
/*   Updated: 2022/05/23 10:01:25 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->next = NULL;
	new->value = value;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack) {
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_pop_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stack_last(*stack);
	if (last)
		last->next = new;
	else
		*stack = new;
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
