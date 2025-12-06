/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:55 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 17:18:00 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
	int	number;
	char	*test_str;

	if (argc > 1)
	{
		test_str = argv[1];
		printf("str to test: %s\n", test_str);
		number = ft_atoi(test_str);
		printf("The number we get from str: %d\n", number);
	}
	else
		printf("ERROR! Not enough argument, need at least 1 str.");
	return (0);
}