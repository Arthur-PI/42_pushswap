/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:06:30 by apigeon           #+#    #+#             */
/*   Updated: 2022/08/02 15:07:12 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
