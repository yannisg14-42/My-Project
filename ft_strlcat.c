/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:01 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 19:37:30 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	to_len;
	size_t	from_len;

	to_len = 0;
	while (dest[to_len])
		to_len++;
	from_len = 0;
	while (src[from_len])
		from_len++;
	if (to_len <= size)
		return (from_len + size);
	i = 0;
	while (src[i] && (to_len + i < size - 1))
	{
		dest[to_len + i] = src[i];
		i++;
	}
	dest[to_len + i] = '\0';
	return (to_len + from_len);
}