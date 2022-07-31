/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:31:50 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/01 00:57:46 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	if (!first || !first->next)
		return ;
	*stack = first->next;
	first->next = NULL;
	last = stack_last(*stack);
	last->next = first;
}

void	rotate_reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*prev;
	t_stack	*curr;

	if (*stack == NULL)
		return ;
	first = *stack;
	prev = first;
	curr = prev;
	while (curr && curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

void	rotate_reverse_both(t_stack **a, t_stack **b)
{
	rotate_reverse(a);
	rotate_reverse(b);
}
