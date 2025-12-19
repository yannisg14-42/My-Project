/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:48:29 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:42:15 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	actual_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (s_len - start))
		actual_len = s_len - start;
	else
		actual_len = len;
	substr = malloc(actual_len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memmove(substr, (s + start), actual_len);
	substr[actual_len] = '\0';
	return (substr);
}
/*
 ft_substr creat a new str that has only 
 a specified segment of s by handling 3 main issues
 boundary check, length calculation and 
 how to allocate-copy-terminate the new str
 the first if loop handle the bad start if it is greater 
 than len then we return an empty str
 after that we must determinate the actual_len of substr 
 since len is just the maximum size allowed, (s_len - start) 
 is the remaining char from start until end of substr
 if the requested len is less than the remaining char then 
 we set actual_len to len
 else if the request len is greater than the remaining char, 
 we cannot go past len so set it to s_len - start
 when we have the actual_len of substr we can allocate memory 
 for it with malloc with 1 extra byte for '\0'
 then we use ft_memmove to copy from s + start to substr, 
 s + start since this hte pointer to the begining of substr in s
 and finaly we place the '\0' at the end since the char 
 are indexed from 0 to actual_len - 1 since a C string must end with the '\0'
*/