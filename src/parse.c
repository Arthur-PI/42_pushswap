/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:21:42 by arthur            #+#    #+#             */
/*   Updated: 2022/05/23 10:18:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_input(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	a = NULL;
	i = 0;
	while (i < ac)
	{
		// replace atoi by the ft one
		tmp = stack_new(atoi(av[i]));
		// handle properly error exit
		if (!tmp)
			exit(1);
		stack_add_back(&a, tmp);
		i++;
	}
	return (a);
}