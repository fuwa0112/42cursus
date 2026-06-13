/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:41:11 by hakama            #+#    #+#             */
/*   Updated: 2026/06/13 21:23:37 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_img_buffer(t_window *window)
{
	ft_memset(&window->img, 0, sizeof(t_img_buffer));
	window->img.img = mlx_new_image(window->mlx, window->width, window->height);
	if (!window->img.img)
		return (NULL);
	window->img.img_addr = mlx_get_data_addr(window->img.img,
			&window->img.bits_per_pixel, &window->img.size_line,
			&window->img.endian);
	if (!window->img.img_addr)
		return (NULL);
	window->img.pixel_size = window->img.bits_per_pixel / 8;
	return (&window->img);
}

void	*destroy_img_buffer(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img.img);
	return (NULL);
}

void	draw_img_buffer(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->x_window, window->img.img, 0,
		0);
}
