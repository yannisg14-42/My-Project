/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 04:23:00 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 18:44:48 by yannis           ###   ########.fr       */
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
/*
 ft_calloc allocate the request memory and return a pointer to it.
 nitems number of element to be allocated 
 and measure is the size of each element
 first we check if one of the argument is 0 we return a unique freeable ptr
 then we check for overflow if it is the case we return NULL, 
 (size_t)-1 is the Max Value of any unsigned type because 
 C guarantees that casting a negative int (-1) 
 to an unsigned type results in the maximum representable value for that type
 after geting the total size of the memory we want 
 to allocate we call malloc for it
 need to check if  for faillure if the ptr is NULL 
 we return NULL immediatly
 the bzero helps to zero-initialize the memory block
 we prefer malloc(1) because with malloc(0) some system 
 might return a valid pointer
*/