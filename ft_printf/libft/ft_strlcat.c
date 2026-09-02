/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:01 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:42:44 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t measure)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (!dest || !src)
		return (0);
	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < measure)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len >= measure)
		return (measure + src_len);
	else
	{
		while (src[i] && (dest_len + i < measure - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
