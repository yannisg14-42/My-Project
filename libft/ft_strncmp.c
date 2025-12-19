/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:46:15 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/19 18:16:33 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
 ft_strncmp should compare 2 str limited to a specified 
 maximum number of char (n)
 the while condition ensure that at most n char are compared
 if the str are different we return the diff
 we enter the else if block means the previous condition is 
 false and both str are equal
 the second check is the check that both string end at 
 the same spot when they are equal
*/