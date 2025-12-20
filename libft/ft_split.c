/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:38:37 by yannis            #+#    #+#             */
/*   Updated: 2025/12/20 11:41:08 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static	int	count_word(char const *s, char c)
{
	int		count;
	int		in_word;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static	void	free_all(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	skip_delimiter(char const *s, size_t i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static char	*extract_word(char const *s, size_t *i, char c)
{
	size_t	start;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = ft_substr(s, start, (*i - start));
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	word_count = count_word (s, c);
	split = ft_calloc((word_count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		i = skip_delimiter(s, i, c);
		if (!s[i])
			break ;
		split[j] = extract_word(s, &i, c);
		if (!split[j])
			return (free_all(split, j), NULL);
		j++;
	}
	return (split);
}
