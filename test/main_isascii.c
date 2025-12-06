/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:20 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:03:11 by sgarba           ###   ########.fr       */
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
		    printf("We are testing with the char: %c(ASCII value %d)\n", test_char, test_char);
		    check = ft_isascii(test_char);
		    printf("1 means is from ascii table and 0 mean the opposite: %d\n", check);
        }
        else
            printf("ERROR! Not enough argument, need at least 1 argument after the program's name");
        return (0);
}