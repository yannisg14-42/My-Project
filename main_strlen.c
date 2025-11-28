/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:41 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 18:18:16 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int  main(int argc, char *argv[])
{
	char	*test_str;
	int	length;

	if (argc > 1)
	{
		test_str = argv[1];
		printf("The str to test: %s\n", test_str);
		length = ft_strlen(test_str);
		printf("the length of the str: %d\n", length);
	}
	else
		printf("ERROR! Not enough argument, need at least 1 str");
	return (0);
}