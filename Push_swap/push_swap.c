/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:10:27 by sgarba            #+#    #+#             */
/*   Updated: 2026/04/28 23:17:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_arg(char *argv[])
{
	int		dup;
	int		number;
	size_t	i;

	i = 0;
	while (argv[i])
	{
		number = ft_is_valid_int(argv[i]);
		if (number == 0)
			return (1);
		i++;
	}
	dup = ft_is_dup(argv);
	if (dup == 1)
		return (1);
	return (0);
}
int main(int argc, char *argv[])
{
	int		valide;
	size_t	i;
	t_stack	a;

	if (argc == 1)
		return (0);
	i = 0;
	valide = ft_validate_arg(argv + 1);
	if (valide == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a.head = NULL;
	a.tail = NULL;
	a.size = 0;
	ft_populate_stack(&a, argv);
	return (0);
}
