/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:39:42 by yannis            #+#    #+#             */
/*   Updated: 2025/12/04 17:39:08 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup_str;
	size_t	str_len;

	str_len = ft_strlen(str);
	dup_str = malloc(str_len + 1);
	if (dup_str == NULL)
		return (NULL);
	ft_memcpy(dup_str, str, (str_len + 1));
	return (dup_str);
}
// ft_strdup is used to duplicate a str, it should return a ptr to a null-terminated dup_str which is the duplicate of str
// the first step is to get the len of str so we know how many bytes we need
// since ft_strlen get the len without the '\0', when we allocate memory for dup_str with malloc we add one more byte
// like always if we cannot provide the requested memory we return NULL to avoid crash
// then we use ft_memcpy to transfer from str to dup_str
// ft_memcpy is fine here instead of ft_memmove since there will be no overlap in the function
// and finally we return the new str
// tldr ft_strdup handles size calculation, memory allocation and data copying