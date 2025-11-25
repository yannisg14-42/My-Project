/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:33:24 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/25 16:36:38 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void  ft_bzero(void *s, size_t n)
{
  size_t  i;
  char	*str;
  
  i = 0;
  while (i <= n-1)
  {
    str[i] = '\0';
    i++;
  }
}
// ft_bzero place n zero-valued bytes in the area pointed to by s
// void *s means generix pointer so it can point to any type of variable

#include <stdio.h>

int  main(int argc, char **argv)
{
  char  *str;

  if (argc == 2)
  {
    str = ft_bzero(argv[1], 10);
  }
  return (0);
}
