/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:46 by arthur            #+#    #+#             */
/*   Updated: 2022/07/14 16:37:16 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_stack  **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putendl("ss");
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_putendl("rr");
}

void    rrr(t_stack **a, t_stack **b)
{
    rotate_reverse(a);
    rotate_reverse(b);
    ft_putendl("rrr");
}
