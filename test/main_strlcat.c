/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:32:54 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/03 04:35:12 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*test_to;
	char	*test_from;
	size_t	n;
	size_t	len;

	if (argc >= 4)
	{
		test_to = argv[1];
		printf("Where to concat: %s\n", test_to);
		test_from = argv[2];
		printf("What to concat: %s\n", test_from);
		n = ft_atoi(argv[3]);
		printf("Total size of the destination buffer: %zu\n", n);
		len = ft_strlcat(test_to, test_from, n);
		printf("The total lenght to return: %zu\n", len);
	}
	else
		printf("ERROR! Not enough argument, need at least 2 str and the size\n");
	return (0);
}