/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:47:02 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/19 18:29:01 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
 ft_lower convert an uppercase char to its lowercase
 if we encounter an uppercase char it is converted to lowercase
 the conversion is done by adding 32 because in ASCII 
 uppercase char are 32 lower than lowercase
*/