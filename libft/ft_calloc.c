/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 04:23:00 by yannis            #+#    #+#             */
/*   Updated: 2025/12/20 11:37:02 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t measure)
{
	size_t	total_size;
	void	*ptr;

	if (nitems == 0 || measure == 0)
		return (malloc(1));
	if (((size_t)-1) / nitems < measure)
		return (NULL);
	total_size = nitems * measure;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
