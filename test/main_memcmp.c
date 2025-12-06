/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:29 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:20:01 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
    char    *test_str1;
	char	*test_str2;
    int	diff;
	size_t	n;

        if (argc >= 4)
        {
            test_str1 = argv[1];
            printf("First str to compare: %s\n", test_str1);
			test_str2 = argv[2];
			printf("str we compare the first one to: %s\n", test_str2);
			n = ft_atoi(argv[3]);
			printf("Number of bytes to be compred: %zu\n", n);
            diff = ft_memcmp(test_str1, test_str2, n);
            printf("0 means both equal, diff > 0 means str1 biger else str2 is biger: %d\n", diff);
        }
        else
            printf("ERROR! Not enough arguments, need at least 2 str and n bytes to be compared");
        return (0);
}