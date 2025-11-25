/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:47:02 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/25 16:47:04 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char  *ft_tolower(char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    i++;
  }
  return (str);
}
// ft_lower read the entire str except the '\0'
// if we encounter an uppercase char it is converted to lowercase
// the conversion is done by adding 32 because in ASCII uppercase char are 32 lower than lowercase

#include <stdio.h>

int  main(int argc, char **argv)
{
  char  *str;

  if (argc == 2)
  {
    str = ft_tolower(argv[1]);
    printf("%s\n", str);
  }
  return (0);
}
