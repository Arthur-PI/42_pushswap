/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:13:49 by apigeon           #+#    #+#             */
/*   Updated: 2022/04/12 17:18:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack  **a)
{
    swap(a);
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
}

void    ra(t_stack **a)
{
    rotate(a);
}

void    rra(t_stack **a)
{
    rotate_reverse(a);
}