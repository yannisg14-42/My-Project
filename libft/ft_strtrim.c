/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:05:27 by yannis            #+#    #+#             */
/*   Updated: 2025/12/20 11:43:41 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		i;
	int		j;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (!s1[0])
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while ((j >= i) && ft_strchr(set, s1[j]))
		j--;
	len = 0;
	if (i <= j)
		len = (j - i) + 1;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, (s1 + i), len);
	new_str[len] = '\0';
	return (new_str);
}
