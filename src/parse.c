/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:21:42 by arthur            #+#    #+#             */
/*   Updated: 2022/07/16 12:36:31 by apigeon          ###   ########.fr       */
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
		tmp = stack_new(ft_atoi(av[i]));
		if (!tmp)
		{
			stack_free(&a);
			return (NULL);
		}
		stack_add_back(&a, tmp);
		i++;
	}
	return (a);
}
