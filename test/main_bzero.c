/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:55:03 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 17:55:18 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
	char	*test_str;
	size_t	n;

	if (argc >= 3)
	{
		test_str = argv[1];
		printf("str to test: %s\n", test_str);
		n = ft_atoi(argv[2]);
		printf("Number of bytes to be filled with zero: %zu\n", n);
		ft_bzero(test_str, n);
		printf("The str after bzero: %s\n", test_str);
	}
	else
		printf("ERROR! Not enough arguments, need at least 1 str and n bytes to fill");
	return (0);
}