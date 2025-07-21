/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:03 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:06:26 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(const char **format, va_list args)
{
	int	count;

	count = 0;
	if (**format == '%')
	{
		(*format)++;
		if (**format)
			count += ft_judgment(args, **format);
		else
			return (-1);
	}
	else
	{
		ft_putchar(**format);
		count++;
	}
	(*format)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		result;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		result = process_format(&format, args);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count += result;
	}
	va_end(args);
	return (count);
}
