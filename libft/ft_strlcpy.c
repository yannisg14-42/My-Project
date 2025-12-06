/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:12 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/04 15:53:12 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t measure)
{
    size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (measure == 0)
		return (src_len);
	while (src[i] && (i  < measure - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
// ft_strlcpy should be more safer and less error-prone alternative to strcpy and strncpy
// prevent buffer overflows by taking the full size of dest as an argument ensuring it never writes past that limit
// it return the number of char it tried to copy which is src_len
// that is why we get first src_len and then copy up to n - 1 char and we terminate with the '\0'