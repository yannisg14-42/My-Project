/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:45 by sgarba            #+#    #+#             */
/*   Updated: 2025/12/04 03:50:11 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	*test_str;
	char	*test_sub_str;
	size_t	n;
	char	*new_str;

	if (argc >= 4)
	{
		test_str = argv[1];
		printf("the str to tes: %s\n", test_str);
		test_sub_str = argv[2];
		printf("the sub_str to find: %s\n", test_sub_str);
		n = ft_atoi(argv[3]);
		printf("the max number of char to search in sub: %d\n", n);
		new_str = ft_strnstr(test_str, test_sub_str, n);
		printf("the str after strnstr: %s\n", new_str);
	}
	else
		printf("ERROR! Not enough argument, need at least 2 str and n char to search\n");
	return (0);
}