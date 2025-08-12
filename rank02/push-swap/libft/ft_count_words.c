/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:14:19 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/12 19:18:34 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *s, char c)
{
	int	wordcount;

	wordcount = 0;
	while (*s)
	{
		if (*s != c)
		{
			wordcount++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (wordcount);
}
