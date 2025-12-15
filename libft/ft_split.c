/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:38:37 by yannis            #+#    #+#             */
/*   Updated: 2025/12/14 17:42:36 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static	int	ft_count_word(char const *s, char c)
{
	int		new_word_start;
	size_t	i;

	i = 0;
	new_word_start = 0;
	if (!s)
		return (0);
	while (s[i + 1])
	{
		if (s[0] != c && s[0] != '\0')
			new_word_start += 1;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			new_word_start += 1;
		i++;
	}
	return (new_word_start);
}

static	void	ft_free_all(char **array, int n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;
	size_t	i, j, start;

	if (!s)
		return (NULL);
	word_count = ft_count_word (s, c);
	split = ft_calloc((word_count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		split[j] = ft_substr(s, start, (i - start));
		if (!split[j])
		{
			ft_free_all(split, j);
			return (NULL);
		}
		j++;
	}
	return (split);
}