/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:51:12 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/30 17:05:53 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = parse_input(ac - 1, av + 1);
	if (!a)
	{
		ft_putendl_fd("Error", 2);
		return (2);
	}
	b = NULL;
	stack_free(&a);
	stack_free(&b);
	return (0);
}
