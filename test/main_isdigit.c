/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:23 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:03:22 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int     main(int argc, char *argv[])
{
    int     check;
    int     test_char;

    if (argc > 1)
    {
        test_char = argv[1][0];
        printf("char to test: %c(ASCII value %d)\n", test_char, test_char);
        check = ft_isdigit(test_char);
        printf("1 means is digit and 0 means isn't: %d\n", check);
    }
    else
        printf("ERROR! Not enough argument, need at least 1 char");
    return (0);
}