/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:00 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/01 22:13:23 by apigeon          ###   ########.fr       */
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
	int	cost_top;
	int	cost_bottom;

	cost_top = i;
	cost_bottom = i - size;
	if (cost_top - cost_a < ft_abs(cost_bottom) + cost_a)
		return (cost_top);
	return (cost_bottom);
}

int	cost_stack_b(t_stack *b, int size, int cost, int a_value)
{
	int		i;
	int		min;
	int		min_index;
	int		max;

	if (!b)
		return (0);
	min = INT_MIN;
	max = min;
	min_index = 0;
	i = 0;
	while (b)
	{
		if (a_value > b->value && b->value > min)
		{
			min = b->value;
			min_index = i;
		}
		else if (min == INT_MIN && b->value > max)
		{
			max = b->value;
			min_index = i;
		}
		b = b->next;
		i++;
	}
	min = cost_to_top_b(min_index, size, cost);
	return (min);
}

int	compute_optimize_cost(int cost_a, int cost_b)
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

t_cost	get_cost(t_stack *a, t_stack *b, int size[2], int i)
{
	int		cost_a[2];
	int		cost_b[2];
	int		cost_opti[2];
	t_cost	cost;

	cost_a[0] = i;
	cost_a[1] = i - size[0];
	cost_b[0] = cost_stack_b(b, size[1], cost_a[0], a->value);
	cost_b[1] = cost_stack_b(b, size[1], cost_a[1], a->value);
	cost_opti[0] = compute_optimize_cost(cost_a[0], cost_b[0]);
	cost_opti[1] = compute_optimize_cost(cost_a[1], cost_b[1]);
	if (cost_opti[0] < cost_opti[1])
	{
		cost.a = cost_a[0];
		cost.b = cost_b[0];
		cost.total = cost_opti[0];
	}
	else
	{
		cost.a = cost_a[1];
		cost.b = cost_b[1];
		cost.total = cost_opti[1];
	}
	return (cost);
}

t_cost	get_min_cost(t_cost a, t_cost b)
{
	if (a.total <= b.total)
		return (a);
	return (b);
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
	int		i;
	int		size[2];
	t_cost	min_cost;
	t_cost	current_cost;
	t_stack	*cur;

	size[0] = stack_size(*a);
	size[1] = stack_size(*b);
	while (*a)
	{
		min_cost.a = size[0];
		min_cost.b = size[1];
		min_cost.total = min_cost.a + min_cost.b;
		cur = *a;
		i = 0;
		while (cur)
		{
			current_cost = get_cost(cur, *b, size, i);
			min_cost = get_min_cost(min_cost, current_cost);
			cur = cur->next;
			i++;
		}
		push_cost(a, b, min_cost);
		size[0] -= 1;
		size[1] += 1;
	}
}

void	put_to_a(t_stack **a, t_stack **b)
{
	int		i;
	int		max;
	int		max_index;
	int		size;
	t_stack	*cur;

	i = 0;
	cur = *b;
	max_index = 0;
	max = cur->value;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			max_index = i;
		}
		i++;
		cur = cur->next;
	}
	size = stack_size(*b);
	max = cost_to_top(size, max_index);
	while (max > 0)
	{
		rb(b);
		max--;
	}
	while (max < 0)
	{
		rrb(b);
		max++;
	}
	i = 0;
	while (i < size)
	{
		pa(a, b);
		i++;
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
	// TODO ça me casse les couilles rien ne va
}

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size > 1)
	{
		sort_idea(a, b);
		put_to_a(a, b);
	}
	else
		sort_small(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = parse_input(ac - 1, av + 1);
	if (!a)
		return (error_msg("Error", 2));
	b = NULL;
	if (!is_sorted(a))
		sort(&a, &b, ac - 1);
	//print_stacks(a, b);
	free_stacks(&a, &b);
	return (0);
}
