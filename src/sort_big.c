/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:34:02 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:05:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cost	get_better_cost(t_stack *a, t_stack *b, int size[2])
{
	int		i;
	t_stack	*cur;
	t_cost	current_cost;
	t_cost	min_cost;

	min_cost.a = size[0];
	min_cost.b = size[1];
	min_cost.total = min_cost.a + min_cost.b;
	cur = a;
	i = 0;
	while (cur)
	{
		current_cost = get_cost(cur, b, size, i);
		min_cost = get_min_cost(min_cost, current_cost);
		cur = cur->next;
		i++;
	}
	return (min_cost);
}

static void	handle_rotate_both(t_stack **a, t_stack **b, t_cost *cost)
{
	while (cost->a < 0 && cost->b < 0)
	{
		rrr(a, b);
		cost->a++;
		cost->b++;
	}
	while (cost->a > 0 && cost->b > 0)
	{
		rr(a, b);
		cost->a--;
		cost->b--;
	}
}

static void	push_cost(t_stack **a, t_stack **b, t_cost cost)
{
	handle_rotate_both(a, b, &cost);
	while (cost.a < 0)
	{
		rra(a);
		cost.a++;
	}
	while (cost.a > 0)
	{
		ra(a);
		cost.a--;
	}
	while (cost.b < 0)
	{
		rrb(b);
		cost.b++;
	}
	while (cost.b > 0)
	{
		rb(b);
		cost.b--;
	}
	pb(b, a);
}

void	sort_big(t_stack **a, t_stack **b)
{
	int		size[2];
	t_cost	cost;

	size[0] = stack_size(*a);
	size[1] = stack_size(*b);
	while (*a)
	{
		cost = get_better_cost(*a, *b, size);
		push_cost(a, b, cost);
		size[0] -= 1;
		size[1] += 1;
	}
}
