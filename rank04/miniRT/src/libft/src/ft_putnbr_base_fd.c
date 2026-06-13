/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:29:07 by hakama            #+#    #+#             */
/*   Updated: 2025/08/04 13:53:52 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long int	nb;
	size_t		byte_cont;
	size_t		base_len;

	nb = n;
	byte_cont = 0;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		nb *= -1;
		byte_cont += ft_putchar_fd('-', fd);
	}
	if (nb < (long int) base_len)
	{
		byte_cont += ft_putchar_fd(base[nb % base_len], fd);
		return (byte_cont);
	}
	byte_cont += ft_putnbr_base_fd(nb / base_len, base, fd);
	byte_cont += ft_putnbr_base_fd(nb % base_len, base, fd);
	return (byte_cont);
}
