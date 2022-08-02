/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:39:05 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:05:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_to_top_b(int i, int size, int cost_a)
{
	int	cost_top;
	int	cost_bottom;

	cost_top = i;
	cost_bottom = i - size;
	if (cost_top <= cost_a)
		return (cost_top);
	if (cost_bottom >= cost_a)
		return (cost_bottom);
	if (cost_top - cost_a < ft_abs(cost_bottom - cost_a))
		return (cost_top);
	return (cost_bottom);
}

static int	compute_optimize_cost(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			cost_a -= cost_b;
		else
			cost_b -= cost_a;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a > cost_b)
			cost_b -= cost_a;
		else
			cost_a -= cost_b;
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

static int	better_cost_b(int i_min, int i_max, int size, int cost_a)
{
	int	cost_min;
	int	cost_max;

	cost_min = INT_MIN + 1;
	cost_max = INT_MAX;
	if (i_min != NOT_FOUND)
		cost_min = cost_to_top_b(i_min, size, cost_a);
	if (i_max != NOT_FOUND)
		cost_max = cost_to_top_b(i_max, size, cost_a);
	return (closest_to_zero(cost_min, cost_max));
}

static int	cost_stack_b(t_stack *b, int size, int cost, int a_value)
{
	int		i;
	int		min[2];
	int		max[2];

	min[0] = INT_MIN;
	max[0] = INT_MAX;
	min[1] = NOT_FOUND;
	max[1] = NOT_FOUND;
	i = -1;
	while (b && ++i >= 0)
	{
		if (b->value < a_value && b->value > min[0])
		{
			min[0] = b->value;
			min[1] = i;
		}
		if (b->value > a_value && b->value < max[0])
		{
			max[0] = b->value;
			max[1] = (i + 1) % size;
		}
		b = b->next;
	}
	i = better_cost_b(min[1], max[1], size, cost);
	return (i);
}

t_cost	get_cost(t_stack *a, t_stack *b, int size[2], int i)
{
	t_cost	cost;

	cost.a = cost_to_top(size[0], i);
	if (b)
		cost.b = cost_stack_b(b, size[1], cost.a, a->value);
	else
		cost.b = 0;
	cost.total = compute_optimize_cost(cost.a, cost.b);
	return (cost);
}
