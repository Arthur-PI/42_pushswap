/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:44:04 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 14:44:29 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(const char *s, int code)
{
	ft_putendl_fd(s, 2);
	return (code);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	stack_free(a);
	stack_free(b);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	closest_to_zero(int a, int b)
{
	if (ft_abs(a) < ft_abs(b))
		return (a);
	return (b);
}
