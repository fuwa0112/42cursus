/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:36:21 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:20 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	draw_bar_only(t_data *data, int y)
{
	int	percent;
	int	width;
	int	x;

	percent = (y * 100) / W_H;
	width = (W_W * percent) / 100;
	x = 25;
	while (x < width - 100)
	{
		put_pixel(data, 0x00FF00, 0, (int []){x, (W_H / 2) - 2});
		put_pixel(data, 0x00FF00, 0, (int []){x, (W_H / 2) - 1});
		put_pixel(data, 0x00FF00, 0, (int []){x, (W_H / 2)});
		put_pixel(data, 0x00FF00, 0, (int []){x, (W_H / 2) + 1});
		put_pixel(data, 0x00FF00, 0, (int []){x, (W_H / 2) + 2});
		x++;
	}
}

char	*get_progress_string(int y)
{
	char	*p;
	char	*result;

	p = ft_itoa((y * 100) / W_H);
	result = ft_strjoin(p, " %");
	free(p);
	return (result);
}

void	display_rendering_text(t_data *data, char *progress)
{
	mlx_put_image_to_window(data->mlx, data->window, data->p_img->image, 0, 0);
	mlx_string_put(data->mlx, data->window, (W_W / 2) - 50, (W_H / 2) - 40,
		0xFFFFFF, "Creating Photo!!");
	mlx_string_put(data->mlx, data->window, (W_W / 2) - 10, (W_H / 2), 0xFFFFFF,
		progress);
}
