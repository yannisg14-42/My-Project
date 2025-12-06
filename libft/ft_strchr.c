/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:48 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:46:27 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char*)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char*)&str[i]);
	return (NULL);
}
// ft_strchr search the first occurence of a char in a str
// important to also check for '\0'
// we return a pointer to the first occurence of c