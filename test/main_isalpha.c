/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:16 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:03:02 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int     main(int argc, char *argv[])
{
    int	check;
    int	test_char;

    if (argc > 1)
    {
        test_char = argv[1][0];
        printf("Char to test: %c(ASCII value %d)\n", test_char, test_char);
        check = ft_isalpha(test_char);
        printf("1 means is from alphabet letter and 0 isn't: %d\n", check);
    }
    else
        printf("ERROR! Not enough argument, need at least 1 char");
    return (0);
}