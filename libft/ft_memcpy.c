/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:38:56 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:40:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*where;
	const unsigned char	*origin;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	where = (unsigned char *)dest;
	origin = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		where[i] = origin[i];
		i++;
	}
	return (dest);
}
