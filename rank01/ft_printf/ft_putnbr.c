/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:22 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putnbr_fd(int n, int fd)
{
	unsigned long	count;
	char			c;

	count = 0;
	if (n == INT_MIN)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}

unsigned long	ft_putnbr_ab(unsigned int n, int fd)
{
	char			buffer[11];
	ssize_t			ret;
	unsigned long	count;
	int				i;

	count = 0;
	i = 0;
	if (n == 0)
		buffer[i++] = '0';
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
	{
		ret = write(fd, &buffer[i], 1);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_convert_to_hex(unsigned int num, char *buffer, int uppercase)
{
	char	*hex_digits;
	int		i;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0 && i < 8)
		{
			buffer[i++] = hex_digits[num % 16];
			num /= 16;
		}
	}
	return (i);
}

ssize_t	ft_write_hex(unsigned int num, int uppercase)
{
	char	buffer[9];
	ssize_t	count;
	ssize_t	ret;
	int		len;

	count = 0;
	len = ft_convert_to_hex(num, buffer, uppercase);
	while (--len >= 0)
	{
		ret = write(1, &buffer[len], 1);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}
