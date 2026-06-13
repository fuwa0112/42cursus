/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:05:46 by hakama            #+#    #+#             */
/*   Updated: 2025/07/24 17:36:01 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	pdest = (unsigned char *) dest;
	psrc = (unsigned char *) src;
	i = 0;
	if (pdest < psrc)
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			pdest[n] = psrc[n];
		}
	}
	return (dest);
}
