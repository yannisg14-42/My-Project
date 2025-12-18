/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:38:37 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 04:36:52 by yannis           ###   ########.fr       */
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
	int	i;

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
/*
 ft_split - Splits a string into array of words using delimiter
 Example: ft_split("hello world", ' ') → ["hello", "world", NULL]
 Returns: Array of strings ending with NULL, or NULL if allocation fails
 ft_count_word - Counts words separated by delimiter 'c'
 A new word starts when: first char != c OR after a delimiter
 Example: "hello world" with c=' ' → returns 2
 ft_free_all - Frees array and all strings in case of allocation failure
 Prevents memory leaks when ft_substr fails midway
 ft_split - Main function
 1. Count words
 2. Allocate array (word_count + 1 for NULL)
 3. Extract each word with ft_substr
 4. Free everything if any allocation fails
*/