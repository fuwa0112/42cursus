/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:19:56 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:11 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_judgment(va_list args, char format)
{
	unsigned long	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (format == 's')
		count = ft_write(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'p')
		count = ft_write_pointer(va_arg(args, void *));
	else if (format == 'u')
		count = ft_putnbr_ab(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		count = ft_write_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count = ft_write_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count = ft_putchar(format);
	return (count);
}
