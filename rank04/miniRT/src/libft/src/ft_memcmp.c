/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:30 by hakama            #+#    #+#             */
/*   Updated: 2025/07/25 19:20:04 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while (n > 0 && (*ps1 == *ps2))
	{
		ps1++;
		ps2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ps1 - *ps2);
}
