/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:21:07 by hakama            #+#    #+#             */
/*   Updated: 2026/06/13 21:22:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel_row(t_window *window, int y, unsigned int *colors)
{
	unsigned int	*row;

	row = (unsigned int *)(window->img.img_addr + y * window->img.size_line);
	ft_memcpy(row, colors, window->width * window->img.pixel_size);
}
