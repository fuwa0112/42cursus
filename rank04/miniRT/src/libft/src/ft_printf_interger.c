/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_interger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:56:09 by hakama            #+#    #+#             */
/*   Updated: 2025/08/04 15:58:58 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_interger(int interger, int fd)
{
	int	p_count;

	p_count = 0;
	p_count += ft_putnbr_fd(interger, fd);
	return (p_count);
}
