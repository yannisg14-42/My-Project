/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:46:34 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 12:08:13 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *sub_str, size_t n)
{
	size_t	i, j;

	i = 0;
	j = 0;
	if (sub_str[j] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (sub_str[j] && (i + j < n) && (str[i + j] == sub_str[j]))
			j++;
		if (sub_str[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
 ft_strnstr should locate a sub_str inside a str
 first we check if the sub_str is empty just return str
 if not  we loop through str find sub_str then loop through it and return we we find the end of sub_str
 if nothing is found we return NULL
 we cast the return to (char *) to tell the computer "sure str was passed as const but I still want to return a non-const pointer"
 j = 0 in the loop because each iteration of outer loop checks if sub_str start at position i in str
 we need to check the entire sub_str from the begining each time so J must start at 0 each time
*/