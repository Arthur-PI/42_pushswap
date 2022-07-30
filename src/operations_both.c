/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:46 by arthur            #+#    #+#             */
/*   Updated: 2022/07/30 22:55:05 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_both(a, b);
	ft_putendl("ss");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_both(a, b);
	ft_putendl("rr");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_reverse_both(a, b);
	ft_putendl("rrr");
}
