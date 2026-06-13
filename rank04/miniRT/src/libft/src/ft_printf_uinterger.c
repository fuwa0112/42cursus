/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uinterger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:56:31 by hakama            #+#    #+#             */
/*   Updated: 2025/08/04 15:59:28 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_uinterger(unsigned int interger, int fd)
{
	int	p_count;

	p_count = 0;
	p_count += ft_putunbr_base_fd(interger, "0123456789", fd);
	return (p_count);
}
