/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:10:27 by sgarba            #+#    #+#             */
/*   Updated: 2026/04/25 22:17:51 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int		number;
	size_t	i;
	int		dup;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		number = ft_is_valid_int(argv[i]);
		if (number == 0)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	dup = ft_is_dup(argv + 1);
	if (dup == 1)
	{
		write (2, "Error\n", 6);
		return (1);
	}
}
