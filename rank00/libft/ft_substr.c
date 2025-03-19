/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:08:37 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/19 18:31:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	actual_len;

	sub = NULL;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = (char *)malloc(1);
		if (sub != NULL)
			sub[0] = '\0';
		return (sub);
	}
	actual_len = s_len - start;
	if (actual_len > len)
		actual_len = len;
	sub = (char *)malloc(actual_len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strncpy(sub, s + start, actual_len);
	sub[actual_len] = '\0';
	return (sub);
}
