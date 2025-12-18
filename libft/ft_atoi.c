/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:37:07 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 05:12:35 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int  ft_atoi(const char *str)
{
	size_t  i; // size_t guaranteed to hold any array index and is not signed 
	int  sign, number;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}
/*
 ft_atoi should check for any type of space according to isspace
 after that the sign variable that define the polarity will always be multiplied by -1 when we encounter a '-'
 then finaly the last formula get all the number in the string by converting the char into an int and adding to the previous number multiplied by 10
*/