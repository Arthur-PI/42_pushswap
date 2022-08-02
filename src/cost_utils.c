/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:37 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:05:24 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	get_min_cost(t_cost a, t_cost b)
{
	if (b.total < a.total)
		return (b);
	return (a);
}

int	cost_to_top(int size, int i)
{
	if (i <= size / 2)
		return (i);
	return (i - size);
}
