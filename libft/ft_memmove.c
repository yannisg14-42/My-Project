/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:14 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:40:27 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
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
