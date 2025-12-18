/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:46:42 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 04:48:07 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(char *str, int c)
{
	size_t	str_len, i;

	str_len = 0;
	while (str[str_len])
		str_len++;
	if (c == '\0')
		return (&str[str_len]);
	i = str_len - 1;
	while (i > 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
 ft_strrchr find the last occurence of a char c
 first we get the len then check if c == '\0' return a pointer to this address with index str_len
 after we do a backward check to search for the last occurence
*/