/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:07:07 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/18 17:39:24 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		value;
	size_t				i;

	p = (const unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == value)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
