/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:12 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:42:51 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t measure)
{
	size_t	src_len;
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (measure == 0)
		return (src_len);
	while (src[i] && (i < measure - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
