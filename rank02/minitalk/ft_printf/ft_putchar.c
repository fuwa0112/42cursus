/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:15 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:13 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putchar_ssize(char c)
{
	return (write(1, &c, 1));
}
