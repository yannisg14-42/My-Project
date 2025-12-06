/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:47 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/04 03:38:25 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
    char    *test_str;
    char    *ptr;
    int     c;

    if (argc >= 3)
    {
        test_str = argv[1];
        printf("str to test: %s\n", test_str);
        c = argv[2][0];
        printf("The bytes of memory we search for: %c\n", c);
        ptr = ft_strrchr(test_str, c);
        printf("The str after strchr: %s\n", ptr);
    }
    else
        printf("ERROR! Not enough arguments, need at least 1 str and the c to search");
    return (0);
}