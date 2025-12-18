/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:14 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 04:42:58 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	const unsigned char	*from;
	size_t	i;

	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i > 0)
		{
			to[i] = from[i];
			i--;
		}
	}
	return (dest);
}
/*
 ft_memmove works likes ft_memcpy
 except now it checks for overlaps by copying the src first in a temporary array buffer
*/