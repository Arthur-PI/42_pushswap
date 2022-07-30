/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:18:19 by arthur            #+#    #+#             */
/*   Updated: 2022/07/30 22:51:48 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	swap(b);
	ft_putendl("sb");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putendl("pb");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl("rb");
}

void	rrb(t_stack **b)
{
	rotate_reverse(b);
	ft_putendl("rrb");
}
