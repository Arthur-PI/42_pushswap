/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:51:12 by apigeon           #+#    #+#             */
/*   Updated: 2022/07/30 18:02:49 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid_operation(const char *s)
{
	int		i;
	char	operations[11][4];

	ft_memcpy(operations[0], "sa\0", 3);
	ft_memcpy(operations[1], "pa\0", 3);
	ft_memcpy(operations[2], "ra\0", 3);
	ft_memcpy(operations[3], "rra\0", 4);
	ft_memcpy(operations[4], "sb\0", 3);
	ft_memcpy(operations[5], "pb\0", 3);
	ft_memcpy(operations[6], "rb\0", 3);
	ft_memcpy(operations[7], "rrb\0", 4);
	ft_memcpy(operations[8], "ss\0", 3);
	ft_memcpy(operations[9], "rr\0", 3);
	ft_memcpy(operations[10], "rrr\0", 4);
	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(s, operations[i], 3) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	remove_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i] = 0;
		i++;
	}
}

int	handle_operation(char *s, t_stack **a, t_stack **b)
{
	remove_newline(s);
	if (!is_valid_operation(s))
		return (FALSE);
	return (TRUE);
}

int	read_operations(t_stack **a, t_stack **b)
{	
	int		err;
	char	*operation;

	operation = get_next_line(1);
	while (operation)
	{
		err = handle_operation(operation, a, b);
		free(operation);
		if (!err)
		{
			get_next_line(-1);
			return (ERROR);
		}
		operation = get_next_line(1);
	}
	return (NO_ERROR);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = parse_input(ac - 1, av + 1);
	b = NULL;
	if (!a)
		return (error_msg("ERROR", 2));
	if (read_operations(&a, &b) == ERROR)
	{
		free_stacks(&a, &b);
		return (error_msg("ERROR", 3));
	}
	if (b == NULL && is_sorted(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stacks(&a, &b);
	return (0);
}
