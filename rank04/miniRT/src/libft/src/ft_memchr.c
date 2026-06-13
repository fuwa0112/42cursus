/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:32 by hakama            #+#    #+#             */
/*   Updated: 2025/07/25 17:35:59 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *) s;
	while (n > 0)
	{
		if (*ps == (unsigned char) c)
			return ((void *) ps);
		ps++;
		n--;
	}
	return ((void *) 0);
}
