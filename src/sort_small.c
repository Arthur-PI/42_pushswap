/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:35:34 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 14:54:24 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_somewhere(t_stack *a)
{
	int		flag;
	t_stack	*cur;

	flag = 0;
	cur = a;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
		{
			if (flag != 0)
				return (FALSE);
			flag = 1;
		}
		cur = cur->next;
	}
	if (cur->value > a->value)
	{
		if (flag != 0)
			return (FALSE);
	}
	return (TRUE);
}

static int	get_bigger_index(t_stack *a, int val)
{
	int		i;
	int		bigger;
	int		bigger_index;
	t_stack	*cur;

	i = 0;
	cur = a;
	bigger = INT_MAX;
	bigger_index = NOT_FOUND;
	while (cur)
	{
		if (cur->value > val && cur->value < bigger)
		{
			bigger = cur->value;
			bigger_index = i;
		}
		cur = cur->next;
		i++;
	}
	if (bigger_index == NOT_FOUND)
		return (get_index(a, get_min_value(a)));
	return (bigger_index);
}

static void	merge(t_stack **a, t_stack **b)
{
	int	index;

	if (*b == NULL)
		return ;
	while (*b)
	{
		index = get_bigger_index(*a, (*b)->value);
		push_top_a(a, index);
		pa(a, b);
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	cost;
	int	index;
	int	size;

	while (stack_size(*a) > 3)
		pb(b, a);
	if (!is_sorted_somewhere(*a))
		sa(a);
	merge(a, b);
	index = get_index(*a, get_min_value(*a));
	size = stack_size(*a);
	cost = cost_to_top(size, index);
	push_top_a(a, cost);
}
