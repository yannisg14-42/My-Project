/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:46:34 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:43:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *sub_str, size_t n)
{
	size_t	i;
	size_t	j;

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
