/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:14 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 05:19:14 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*where;
	const unsigned char	*origin;
	size_t	i;

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
 except now it checks for overlaps by copying the src first in a temporary array buffer
*/