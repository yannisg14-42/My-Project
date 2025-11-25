/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:37:28 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/25 19:45:28 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*int  ft_atoi(const char *str)
{
	size_t  i; 
	int  sign;
	int  number;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
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
}*/


int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || 
		(c >= 'A' && c <= 'Z') || 
		(c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
// ft_isalnum will take the ASCII as argument
// and return a non 0 digit it is the ASCII of an alphanumeric char
// else it return 0

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	rt;

	if (argc == 2)
	{
		rt = ft_isalnum(argv[1]);
		printf("%d\n", rt);
	}
	return (0);
}

