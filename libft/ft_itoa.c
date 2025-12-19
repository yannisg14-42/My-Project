/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:42:21 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:42:58 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static	int	digit_count(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		digit_total;
	size_t	i;
	long	nb;

	if (n == 0)
		return (ft_strdup("0"));
	digit_total = digit_count(n);
	new_str = ft_calloc((digit_total + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	nb = n;
	if (n < 0)
	{
		new_str[0] = '-';
		nb *= -1;
	}
	i = digit_total - 1;
	while (nb != 0)
	{
		new_str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (new_str);
}
/*
 ft_itoa means int to array, it receive an int as parameter and 
 turn it into char to put it in an array
 we turn our int n into long nb to avoid overflow
 i first procceed to write and helper that count all digit
 in case our n is 0 we just return(1), because we have 1 digit + the \0 later
 returning 1 help allocate enough space
 When we have negative number we increment 1 time to save for '-' 
 then turn nb to positive
 and when n != 0 we keep /10 to get the next digit, 
 count++ and return (count)
 Now that we have the helper, in ft_itoa we simply call it 
 to know how much space we must allocate
 we assign int n to long nb in to avoid overflow
 if nb < 0 we set the first char to '-' then turn it into positive
 else we set i to first valid char digit_total - 1
 then for each %10 + '0' to turn int into char, 
 then /10 to get next digit and we keep decrementing 
*/