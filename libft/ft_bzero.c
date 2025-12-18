/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:33:24 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 04:40:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
 	char	*str;
 
  	str = (char *)ptr; // how to cast the void pointer
  	i = 0;
  	while (i < n)
  	{
    	str[i] = '\0';
    	i++;
  	}
}
/*
 ft_bzero place n zero-valued bytes in the area pointed to by s
 void *s means generic pointer, so it can point to any type of variable
 n is the number of bytes to be set to '\0'
 since ft_bzero place the'\0' at the begining of str, printf treat it as an empty str therefore no ouptput
*/