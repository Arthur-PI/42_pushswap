/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:00 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/20 22:56:02 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	printf("Stacks:\n");
	while (len_a != len_b)
	{
		if (len_a > len_b)
		{
			printf("%5d\t\n", a->value);
			a = a->next;
			len_a--;
		}
		else
		{
			printf(" \t%5d\n", b->value);
			b = b->next;
			len_b--;
		}
	}
	while (len_a > 0)
	{
		printf("%5d\t%5d\n", a->value, b->value);
		a = a->next;
		b = b->next;
		len_a--;
	}
	printf("    _\t    _\n    a\t    b\n");
}

int	cost_to_top(int size, int i)
{
	if (i <= size / 2)
		return (i);
	return (i - size);
}

int	cost_to_top_b(int i, int size, int cost_a)
{
	int cost_top;
	int cost_bottom;

	cost_top = i;
	cost_bottom = i - size;
	if (cost_top - cost_a < ft_abs(cost_bottom) + cost_a)
		return (cost_top);
	return (cost_bottom);
}

int	cost_b(t_stack *b, int size, int cost, int a_value)
{
	int		i;
	int		max;
	int		min;
	int		min_index;

	if (!b)
		return (0);
	min = INT_MIN + 1;
	max = min;
	min_index = 0;
	i = 0;
	while (b)
	{
		if (b->value < a_value && b->value > min)
		{
			min = b->value;
			min_index = i;
		}
		else if (min == INT_MIN + 1 && b->value > max)
		{
			max = b->value;
			min_index = i;
		}
		//printf("min_index = %d\n", min_index);
		b = b->next;
		i++;
	}
	min = cost_to_top_b(min_index, size, cost);
	return (min);
}

int	compute_optimize_cost(t_cost cost)
{
	if (cost.a > 0 && cost.b > 0)
	{
		if (cost.a > cost.b)
			cost.a -= cost.b;
		else
			cost.b -= cost.a;
	}
	else if (cost.a < 0 && cost.b < 0)
	{
		if (cost.a > cost.b)
			cost.b -= cost.a;
		else
			cost.a -= cost.b;
	}
	return (ft_abs(cost.a) + ft_abs(cost.b));

}

t_cost	get_cost(t_stack *a, t_stack *b, t_cost size, int i)
{
	t_cost cost;

	cost.a = cost_to_top(size.a, i);
	cost.b = cost_b(b, size.b, cost.a, a->value);
	//printf("Cost of %d -> (%d,%d) = %d\n", a->value, cost.a, cost.b, compute_optimize_cost(cost));
	return (cost);
}

t_cost	get_min_cost(t_cost a, t_cost b)
{
	if (compute_optimize_cost(a) > compute_optimize_cost(b))
		return (b);
	return (a);
}

void	push_cost(t_stack **a, t_stack **b, t_cost cost)
{
	if (cost.a <= 0)
	{
		if (cost.b < 0)
		{
			while (cost.a && cost.b)
			{
				rrr(a, b);
				cost.a++;
				cost.b++;
			}
			while (cost.b)
			{
				rrb(b);
				cost.b++;
			}
		}
		else
		{
			while (cost.b)
			{
				rb(b);
				cost.b--;
			}
		}
		while (cost.a)
		{
			rra(a);
			cost.a++;
		}
	}
	if (cost.a > 0)
	{
		if (cost.b > 0)
		{
			while (cost.a && cost.b)
			{
				rr(a, b);
				cost.a--;
				cost.b--;
			}
			while (cost.b)
			{
				rb(b);
				cost.b--;
			}
		}
		else
		{
			while (cost.b)
			{
				rrb(b);
				cost.b++;
			}
		}
		while (cost.a)
		{
			ra(a);
			cost.a--;
		}
	}
	pb(b, a);
}

void	sort_idea(t_stack **a, t_stack **b)
{
	int	i;
	t_cost	size;
	t_cost	min_cost;
	t_cost	tmp;
	t_stack	*cur;

	i = 0;
	size.a = stack_size(*a);
	size.b = stack_size(*b);
	while (a)
	{
		min_cost.a = size.a;
		min_cost.b = size.b;
		cur = *a;
		while (cur)
		{
			tmp = get_cost(cur, *b, size, i);
			min_cost = get_min_cost(min_cost, tmp);
			i++;
			cur = cur->next;
		}
		printf("Min cost = (%d,%d)\n", min_cost.a, min_cost.b);
		push_cost(a, b, min_cost);
		size.a--;
		size.b++;
	}
	// For each element in stack a find the cost to move to the top
	// It will be a negative number if using rra and positive if using ra
	// Find the closest bigger and smaller number of the number we looking in b
	// For each of the two calculate the cost of moving it to the top
	// Taking into consideration the use of rr and rrr to optimize cost
	// Once done give the total cost
	// At the end move the on number in a that has the less cost
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	a = parse_input(ac - 1, av + 1);
	if (!a)
		return (1);
	b = NULL;
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	//simple_sort(&a, &b);
	sort_idea(&a, &b);
	print_stacks(a, b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
