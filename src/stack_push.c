/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:43:13 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:03:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_a(t_stack **a, int cost)
{
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

static void	push_top_b(t_stack **b, int cost)
{
	while (cost > 0)
	{
		rb(b);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b);
		cost++;
	}
}

void	put_to_a(t_stack **a, t_stack **b)
{
	int		max_index;
	int		cost;

	max_index = get_index(*b, get_max_value(*b));
	cost = cost_to_top(stack_size(*b), max_index);
	push_top_b(b, cost);
	while (*b)
		pa(a, b);
}
