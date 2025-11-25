/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:27 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/25 16:44:45 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int  ft_strlen(const char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
//ft_strlen keep incrementing in the string and stop at the '\0'
//then at the end return an integer i that is the length of the string

#include <stdio.h>

int  main(int argc, const char **argv)
{
  int  length;

  if (argc == 2)
  {
    length = ft_strlen(argv[1]);
    printf("the length of the string is %d\n", length);
  }
  return (0);
}
