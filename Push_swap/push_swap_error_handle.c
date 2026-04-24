/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:37:59 by sgarba            #+#    #+#             */
/*   Updated: 2026/04/24 22:13:36 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_int(char *result)
{
	long	digit;
	int		sign;
	size_t	i;
	
	i = 0;
	while (result[i] == ' ' || (result[i] >= 9 && result[i] <= 13))
		i++;
	sign = 1;
	if (result[i] == '+' || result[i] == '-')
	{
		if (result[i] == '-')
			sign = -1;
		i++;
	}
	if (!(result[i] >= '0' && result[i] <= '9'))
		return (0);
	digit = 0;
	while (result[i] >= '0' && result[i] <= '9')
	{
		digit = (digit * 10) + (result[i] - '0');
		i++;
	}
	if (digit * sign > INT_MAX || digit * sign < INT_MIN)
		return (0);
	return (1);
}