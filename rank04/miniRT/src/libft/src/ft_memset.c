/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:02:12 by hakama            #+#    #+#             */
/*   Updated: 2025/07/24 17:40:06 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sp;
	size_t			i;

	i = 0;
	sp = (unsigned char *) s;
	while (i < n)
	{
		sp[i] = c;
		i++;
	}
	return (s);
}
