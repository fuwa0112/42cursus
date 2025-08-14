/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:42 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:20 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_address_to_hex(unsigned long address, char *buffer)
{
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (address > 0 && i < 16)
	{
		buffer[i++] = hex_digits[address % 16];
		address /= 16;
	}
	return (i);
}

ssize_t	ft_write_prefix(void)
{
	return (write(1, "0x", 2));
}

ssize_t	ft_write_buffer(const char *buffer, int len)
{
	ssize_t	ret;
	ssize_t	count;

	count = 0;
	while (--len >= 0)
	{
		ret = write(1, &buffer[len], 1);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}

unsigned long	ft_write_nil(void)
{
	ssize_t	ret;

	ret = write(1, "(nil)", 5);
	if (ret < 0)
		return (0);
	return (5);
}

unsigned long	ft_write_pointer(void *ptr)
{
	unsigned long	address;
	char			buffer[17];
	ssize_t			ret;
	unsigned long	count;
	int				i;

	count = 0;
	if (!ptr)
		return (ft_write_nil());
	address = (unsigned long)ptr;
	i = ft_convert_address_to_hex(address, buffer);
	ret = ft_write_prefix();
	if (ret < 0)
		return (0);
	count += ret;
	ret = ft_write_buffer(buffer, i);
	if (ret < 0)
		return (0);
	count += ret;
	return (count);
}
