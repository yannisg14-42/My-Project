/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:39 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/04 00:44:22 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*test_dest;
	char	*test_src;
	size_t	n;
	size_t	len;

	if (argc >= 4)
	{
		test_dest = argv[1];
		printf("Where to concat: %s\n", test_dest);
		test_src = argv[2];
		printf("What to concat: %s\n", test_src);
		n = ft_atoi(argv[3]);
		printf("Total size of the destination buffer: %zu\n", n);
		len = ft_strlcpy(test_dest, test_src, n);
		printf("The total lenght to return: %zu\n", len);
	}
	else
		printf("ERROR! Not enough argument, need at least 2 str and the size\n");
	return (0);
}