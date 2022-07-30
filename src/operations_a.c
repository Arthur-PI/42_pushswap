/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:13:49 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/30 22:57:15 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
	ft_putendl("sa");
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl("pa");
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl("ra");
}

void	rra(t_stack **a)
{
	rotate_reverse(a);
	ft_putendl("rra");
}
