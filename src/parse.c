/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:21:42 by arthur            #+#    #+#             */
/*   Updated: 2022/07/30 22:55:35 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	custom_atoi(char *s, int *err)
{
	int		i;
	int		sign;
	long	n;

	*err = ERROR;
	if (!s)
		return (0);
	i = 0;
	sign = get_sign(s[i]);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	n = 0;
	while (ft_isdigit(s[i]) && i < 11)
		n = (n * 10) + (s[i++] - '0');
	n *= sign;
	if (s[i] != 0 || i == 0 || n > INT_MAX || n < INT_MIN)
		return (0);
	*err = NO_ERROR;
	return (n);
}

int	have_duplicate(t_stack *stack)
{
	int		number;
	t_stack	*cur;

	while (stack->next)
	{
		number = stack->value;
		cur = stack->next;
		while (cur)
		{
			if (number == cur->value)
				return (TRUE);
			cur = cur->next;
		}
		stack = stack->next;
	}
	return (FALSE);
}

t_stack	*parse_input(int ac, char **av)
{
	int		i;
	int		err;
	t_stack	*a;
	t_stack	*tmp;

	a = NULL;
	err = NO_ERROR;
	i = 0;
	while (i < ac)
	{
		tmp = stack_new(custom_atoi(av[i], &err));
		stack_add_back(&a, tmp);
		if (!tmp || err == ERROR)
		{
			stack_free(&a);
			return (NULL);
		}
		i++;
	}
	if (have_duplicate(a) == TRUE)
	{
		stack_free(&a);
		return (NULL);
	}
	return (a);
}
