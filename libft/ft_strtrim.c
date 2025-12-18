/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:05:27 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 04:48:37 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len, i, j;
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
/*
 ft_strtrim trim s1 with the char is set
 we first check some edge cases aka if s1 is NULL we return NULL and if s1 is empty we return the dup of an empty str
 now the the first loop is to find the first char for new_str
 we check while s1[i] so we know we don't reach end of s1 and strchr find the first occurence of s1 in set so i point to the first char of new_str
 the second loop is to find tje last chae in new_str
 we initialize j to the last char of s1 with strlen(s1)-1
 j >= i is for the backward loop so we don't cross starting boundary and strchr find the first occurence of the end char in set  and now j point to the last char in new_str
 i <= j means we found the segment  in new_str and the correct inclusive len is j-i+1, if i>j when full trimmed then the len is 0 so no copy
 then we allocate enlugh space since we have the len and +1 byte for the \0, we also chaeck if allocation fail we return NULL
 memmove does the copying in new_str from the starting point of the first char to keep  which is s1+i and we place the \0 at the end to have a proper C str
*/