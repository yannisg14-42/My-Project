/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:46:42 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/20 11:50:41 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	str_len;
	size_t	i;

	str_len = 0;
	while (str[str_len])
		str_len++;
	if (c == '\0')
		return (&str[str_len]);
	i = str_len;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (&str[i]);
	}
	return (NULL);
}
