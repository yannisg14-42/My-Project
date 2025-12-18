/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:38:56 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 12:13:07 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	const unsigned char	*from;
	size_t	i;

	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}
/*
 ft_memcpy copy n bytes from dest to src
 undefined behaviour if both str overlap (memcpy doesn't check for it)
*/