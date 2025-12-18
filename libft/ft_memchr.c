/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:38:25 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 04:41:59 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *ptr, int c, size_t n)
{
	unsigned char	*str;
	size_t	i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
 ft_memchr search a block of memory for a specific byte regardless of it's content
 since it searches raw memory the search must not stop when encountering '\0' but continue checking up to n bytes that is why we don't need the condtion (str[i] != \0)
 str[i] == str[c] is wrong because I want just want to compare the byte at the current i position against c
 str[i] == str[c] means I am trying to access the memory location at str plus an offset equal to the value of the char I am searching
*/