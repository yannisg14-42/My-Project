/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:38:37 by yannis            #+#    #+#             */
/*   Updated: 2025/12/19 19:20:47 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static	int	count_word(char const *s, char c)
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
/*
 ft_split - Splits a string into array of words using delimiter
 Example: ft_split("hello world", ' ') → ["hello", "world", NULL]
 Returns: Array of strings ending with NULL, or NULL if allocation fails
 count_word - Counts words separated by delimiter 'c'
 A new word starts when: first char != c OR after a delimiter
 Example: "hello world" with c=' ' → returns 2
 free_all - Frees array and all strings in case of allocation failure
 Prevents memory leaks when ft_substr fails midway
 skip_delimiter skip all consecutive delimiter and return
 the position of the next char
 extract_word extract a word starting from position i
 since we are in a str inside a str we dereference i and
 return the to be extracted with ft_substr
 ft_split - Main function
 1. Count words
 2. Allocate array (word_count + 1 for NULL)
 3. Extract each word with ft_substr
 4. Free everything if any allocation fails
*/