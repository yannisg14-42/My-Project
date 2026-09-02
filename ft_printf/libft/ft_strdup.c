/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:39:42 by yannis            #+#    #+#             */
/*   Updated: 2025/12/20 11:53:34 by yannis           ###   ########.fr       */
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
