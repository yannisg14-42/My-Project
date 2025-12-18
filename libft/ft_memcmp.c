/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:38:43 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 04:42:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*str1, *str2;
	size_t	i;

	str1 = (const unsigned char *)ptr1;
	str2 = (const unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
 ft_memcmp will compare 2 memory blocks
 if they are different it return the difference, else the are both equal and return 0
 diff < 0 means str1 is biger else str2 is bigger
*/