/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:08:23 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/19 18:29:52 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*word_alloc(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = word_length(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	populate_words(char **result, const char *s, char c)
{
	int		index;
	char	*word;

	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			word = word_alloc(s, c);
			if (!word)
			{
				while (index > 0)
					free(result[--index]);
				return (0);
			}
			result[index++] = word;
			s += word_length(s, c);
		}
		else
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!populate_words(result, s, c))
	{
		free(result);
		return (NULL);
	}
	result[words] = NULL;
	return (result);
}
