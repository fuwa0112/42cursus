/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:30 by thitoe            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:18 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t	ft_write(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	i = ft_strlen(str);
	ft_putstr(str, 1);
	return (i);
}
