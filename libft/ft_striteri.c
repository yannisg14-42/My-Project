/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:46:19 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:57:54 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// ft_striteri is also modify the string but the original directly
// not like ft_strmapi that store the result in a new_str
// we pass directly the address of each char therefor &s[i]
// void function so no return