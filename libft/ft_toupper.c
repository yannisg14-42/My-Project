/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:47:11 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/18 05:35:38 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_toupper(int c)
{
	if( c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}
/*
 ft_toupper will converts lowercase char to their uppercase
 the conversion is done by substracting 32 because in ASCII lowercase char are 32 higher than uppercase
*/