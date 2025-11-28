/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:47:11 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:46:44 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char  *ft_toupper(char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - 32;
    i++;
  }
  return (str);
}
// ft_toupper will read the entire string except '\0'
// while reading if it encounter a lowercase char it convert it uppercase
// the conversion is done by substracting 32 because in ASCII lowercase char are 32 higher than uppercase