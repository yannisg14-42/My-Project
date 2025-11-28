/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:35 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:07:51 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
    char    *test_str;
    char    *ptr;
    size_t  n;
    int     c;

    if (argc >= 4)
    {
        test_str = argv[1];
        printf("str to test: %s\n", test_str);
        c = argv[2][0];
        printf("The byte that modify the str: %c\n", c);
        n = ft_atoi(argv[3]);
        printf("Number of bytes to be changed: %zu\n", n);
        ptr = ft_memset(test_str, c, n);
        printf("The str after memset: %s\n", ptr);
    }
    else
        printf("ERROR! Not enough arguments, need at least 1 str, the c to set and n bytes");
    return (0);
}