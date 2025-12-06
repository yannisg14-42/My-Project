/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:17:35 by yannis            #+#    #+#             */
/*   Updated: 2025/12/05 01:57:02 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_str = malloc(total_len + 1);
	if(new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy((new_str + s1_len), s2, s2_len);
	new_str[total_len] = '\0';
	return(new_str);
}
// ft_strjoin should join 2 cosnt str
// the firsts if loop check for no segfault when we pass a NULL pointer by reassigning them to an empty string literal if one of them is NULL
// the next section help get the exact size needed for new_str
// after that we allocate enough space with malloc and the total_len, +1 for the '\0', also checking if malloc fail too return NULL
// then we copy two to append the 2 str
// first copy from s1 to new_str with the len of s1
// then for the second copy we use new_str + s1_len to point after s1 so we can apend without overlap at the end of s1
// and finally we place the '\0' at the end to have a proper C str