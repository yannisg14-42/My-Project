/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:43:25 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:17:39 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = ft_calloc((s_len + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}
/*
 ft_strmapi is a function that map 
 a string using another function
 it iterate through s then for each char it call f with 2 arguments 
 (char index, char)
 then collect the result and put it in a new string
*/