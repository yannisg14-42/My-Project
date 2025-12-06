/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:33 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:18:56 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char    *test_to;
    char    *test_from;
    char	*new_str;
    size_t  n;

    if (argc >= 4)
    {
        test_to = argv[1];
        printf("Where to copy: %s\n", test_to);
        test_from = argv[2];
        printf("what to copy: %s\n", test_from);
        n = ft_atoi(argv[3]);
        printf("Number of bytes to copy: %zu\n", n);
        new_str = ft_memmove(test_to, test_from, n);
        printf("The str after memmove: %s\n", new_str);
    }
    else
        printf("ERROR! Not enough arguments, need at least 2 str and n bytes to copy.\n");
    return (0);
}