/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:14 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/19 18:23:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*where;
	const unsigned char	*origin;
	size_t				i;

	where = (unsigned char *)dest;
	origin = (const unsigned char *)src;
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			where[i] = origin[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			where[i] = origin[i];
		}
	}
	return (dest);
}
/*
 ft_memmove works likes ft_memcpy
 we decrement first to avoid out of bound and because our 
 first starting index is not valid
 so we decremt first to convert to valid index then we workd with our str
 if we where to start at n - 1 so already vaild index then we 
 decrement after and work till i >= 0
 but need to be careful with unsigned because when i = 0, i--makes it wrap around
 except now it checks for overlaps by copying the src 
 first in a temporary array buffer
*/