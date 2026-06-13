/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:06:25 by hakama            #+#    #+#             */
/*   Updated: 2025/07/26 19:04:07 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	res = (char *) malloc((s_len + 1) * sizeof(char));
	if (!res)
		return ((void *) 0);
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
