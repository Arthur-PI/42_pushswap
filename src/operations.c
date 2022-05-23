/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:31:50 by apigeon           #+#    #+#             */
/*   Updated: 2022/05/23 10:48:03 by arthur           ###   ########.fr       */
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

	tmp = *b;
	if (!b)
		return ;
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