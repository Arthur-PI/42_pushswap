/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:00 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/16 12:39:54 by apigeon          ###   ########.fr       */
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

void	simple_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			sa(&a);
		pb(&b, &a);
		//print_stacks(*a, *b);
	}
	pb(&b, &a);
}

int	cost_to_top(int size, int i)
{
	if (i < size / 2)
		return (i);
	return (i - size);
}

int	cost_to_top_b(int i, int size, int cost_a)
{
	int cost_top;
	int cost_bottom;

	cost_top = i;
	cost_bottom = i - size;
	if (cost_a > 0)
	{
		if (cost_a > cost_top)
			cost_top = 0;
		else
			cost_top -= cost_a;
	}
	else
	{
		if (cost_a < cost_bottom)
			cost_bottom = 0;
		else
			cost_bottom -= cost_a;
	}
	if (ft_abs(cost_bottom) < cost_top)
		return (cost_bottom);
	return (cost_top);
}

int	cost_b(t_stack *b, int size, int cost, int a_value)
{
	int		min;
	int		min_index;
	int		max;
	int		max_index;
	int		i;
	t_stack	*cur;

	if (!b)
		return (0);
	cur = b;
	min = b->value;
	max = b->value;
	min_index = 0;
	max_index = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < a_value && cur->value > min)
		{
			min = cur->value;
			min_index = i;
		}
		if (cur->value > a_value && cur->value < max)
		{
			max = cur->value;
			max_index = i;
		}
		cur = cur->next;
		i++;
	}
	min = cost_to_top_b(min_index, size, cost);
	max = cost_to_top_b(max_index, size, cost);
	if (ft_abs(min) < ft_abs(max))
		return (min);
	return (max);
}

void	sort_idea(t_stack *a, t_stack *b)
{
	int	i;
	int	a_size;
	int	b_size;
	int	a_cost;
	int	b_cost;
	int	cost;

	i = 0;
	a_size = stack_size(a);
	b_size = stack_size(b);
	cost = a_size + b_size;
	while (a)
	{
		a_cost = cost_to_top(a_size, i);
		b_cost = cost_b(b, b_size, a_cost, a->value);
		cost = ft_min(cost, ft_abs(a_cost) + ft_abs(b_cost) + 1);
		i++;
	}
	printf("cost = %d\n", cost);
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
	//simple_sort(&a, &b);
	sort_idea(a, b);
	print_stacks(a, b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
