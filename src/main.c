/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:00 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/14 15:41:28 by apigeon          ###   ########.fr       */
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
			printf("%5d\t\n", a->value);
			a = a->next;
			len_a--;
		}
		else
		{
			printf(" \t%5d\n", b->value);
			b = b->next;
			len_b--;
		}
	}
	while (len_a > 0)
	{
		printf("%5d\t%5d\n", a->value, b->value);
		a = a->next;
		b = b->next;
		len_a--;
	}
	printf("    _\t    _\n    a\t    b\n");
}

void	simple_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			sa(&a);
		pb(&b, &a);
		//print_stacks(*a, *b);
	}
	pb(&b, &a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	a = parse_input(ac - 1, av + 1);
	if (!a)
		return (1);
	b = NULL;
	//simple_sort(&a, &b);
	print_stacks(a, b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
