/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:00 by apigeon           #+#    #+#             */
/*   Updated: 2022/05/23 10:52:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	printf("Stacks:\n");
	while (len_a != len_b)
	{
		if (len_a > len_b)
		{
			printf("%3d\t\n", a->value);
			a = a->next;
			len_a--;
		}
		else
		{
			printf(" \t%3d", b->value);
			b = b->next;
			len_b--;
		}
	}
	while (len_a > 0)
	{
		printf("%3d\t%3d\n", a->value, b->value);
		a = a->next;
		b = b->next;
		len_a--;
	}
	printf("  _\t  _\n  a\t  b\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	a = parse_input(ac - 1, av + 1);
	b = NULL;
	print_stacks(a, b);
	return (0);
}
