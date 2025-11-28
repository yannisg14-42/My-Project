/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:32:54 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 19:25:21 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*test_to;
	char	*test_from;
	size_t	siz;
	size_t	len;

	if (argc >= 4)
	{
		test_to = argv[1];
		printf("Where to concat: %s\n", test_to);
		test_from = argv[2];
		printf("What to concat: %s\n", test_from);
		siz = ft_atoi(argv[3]);
		printf("Total size of the destination buffer: %zu\n", siz);
		len = ft_strlcat(test_to, test_from, siz);
		printf("The total lenght to return: %zu\n", len);
	}
	else
		printf("ERROR! Not enough argument, need at least 2 str and the size");
	return (0);
}