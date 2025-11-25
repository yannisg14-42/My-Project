/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:37:40 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/25 16:37:43 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int  ft_isalpha(const char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
  {
    if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
      return (0);
    i++;
  }
  return (1);
}

//ft_isalpha will check all characters of the string
//and return 0 immediatly, if a character is not an alphabet
//else it continue to increment and return 1 if all characters are alphabet

#include <stdio.h>

int  main(int argc, const char **argv)
{
  int  detect;

  if (argc == 2)
  {
    detect = ft_isalpha(argv[1]);
    printf("%d\n", detect);
  }
  return (0);
}
