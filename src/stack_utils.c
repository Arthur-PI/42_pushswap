/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:37:35 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 14:37:59 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		min = ft_min(min, stack->value);
		stack = stack->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		max = ft_max(max, stack->value);
		stack = stack->next;
	}
	return (max);
}

int	get_index(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == val)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
