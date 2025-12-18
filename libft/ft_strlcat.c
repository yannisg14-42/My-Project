/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:01 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 11:58:20 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t measure)
{
	size_t	i, dest_len, src_len;

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
		return (dest_len + src_len);
	else
	{
		while (src[i] && (dest_len + i  < measure - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
	
}
/*
 ft_strlcat purpose is to safely concatenate str into a fixe siz dest buffer
 first I get dest_len with the condition that it should be less than siz so i don't read past boundary
 then I get src_len
 we early return the total that shoulb habe been concat if dest_len >= siz because it would mean the dest buffer is overflown so it should not copy
 else we from src to dest up siz - 1 to reserve space for '\0' the we add at the end of the loop and we return the total len
*/