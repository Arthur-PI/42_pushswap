/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:18:19 by arthur            #+#    #+#             */
/*   Updated: 2022/04/12 17:27:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_stack  **b)
{
    swap(b);
}

void    pb(t_stack **b, t_stack **a)
{
    push(b, a);
}

void    rb(t_stack **b)
{
    rotate(b);
}

void    rrb(t_stack **b)
{
    rotate_reverse(b);
}