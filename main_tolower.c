/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:48 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:21:22 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
  char  *test_str;
  char  *new_str;

  if (argc > 1)
  {
    test_str = argv[1];
    printf("str to test: %s\n", test_str);
    new_str = ft_tolower(test_str);
    printf("The str after tolower: %s\n", new_str);
  }
  else
    printf("ERROR! Not enough arguments, need at least 1 str");
  return (0);
}