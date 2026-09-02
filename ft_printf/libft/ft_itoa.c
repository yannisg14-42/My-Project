/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:42:21 by yannis            #+#    #+#             */
/*   Updated: 2025/12/20 11:38:12 by yannis           ###   ########.fr       */
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
