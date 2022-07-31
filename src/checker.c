/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:51:12 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/01 01:08:06 by apigeon          ###   ########.fr       */
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

void	do_operation(char *s, t_stack **a, t_stack **b)
{
	if (ft_strncmp(s, "sa", 3) == 0)
		swap(a);
	else if (ft_strncmp(s, "pa", 3) == 0)
		push(a, b);
	else if (ft_strncmp(s, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(s, "rra", 3) == 0)
		rotate_reverse(a);
	else if (ft_strncmp(s, "sb", 3) == 0)
		swap(b);
	else if (ft_strncmp(s, "pb", 3) == 0)
		push(b, a);
	else if (ft_strncmp(s, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		rotate_reverse(b);
	else if (ft_strncmp(s, "ss", 3) == 0)
		swap_both(a, b);
	else if (ft_strncmp(s, "rr", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(s, "rrr", 3) == 0)
		rotate_reverse_both(a, b);
}

int	handle_operation(char *s, t_stack **a, t_stack **b)
{
	remove_newline(s);
	if (!is_valid_operation(s))
		return (FALSE);
	do_operation(s, a, b);
	return (TRUE);
}

int	read_operations(t_stack **a, t_stack **b)
{	
	int		err;
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		err = handle_operation(operation, a, b);
		free(operation);
		if (!err)
			return (ERROR);
		operation = get_next_line(0);
		usleep(200);
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
		return (error_msg("Error", 2));
	if (read_operations(&a, &b) == ERROR)
	{
		free_stacks(&a, &b);
		return (error_msg("Error", 3));
	}
	if (b == NULL && is_sorted(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stacks(&a, &b);
	return (0);
}
