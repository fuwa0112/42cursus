/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 02:46:34 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:21:35 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	anti_aliasing(t_data *data, int x, int y)
{
	t_ray	ray;
	t_vec3	sample;
	t_vec3	avg;
	int		i;

	i = 0;
	avg = vec(0, 0, 0);
	while (i < SAMPLES_PER_PIXEL)
	{
		ray = get_ray(data, x, y);
		sample = color_to_vec3(trace_ray(ray, data, DEPTH));
		avg = vec_add(avg, sample);
		i++;
	}
	avg = vec_mul(avg, 1.0 / SAMPLES_PER_PIXEL);
	avg.x = fmin(avg.x, 255);
	avg.y = fmin(avg.y, 255);
	avg.z = fmin(avg.z, 255);
	return (avg);
}

void	render_scene(t_data *data)
{
	char	*progress_str;
	t_vec3	avg;
	int		y;
	int		x;

	y = 0;
	while (y < data->img->img_h)
	{
		x = 0;
		while (x < data->img->img_w)
		{
			avg = anti_aliasing(data, x, y);
			put_pixel(data, vec3_to_int(avg), 1, (int []){x, y});
			x++;
		}
		progress_str = get_progress_string(y);
		display_rendering_text(data, progress_str);
		free(progress_str);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->image, 0, 0);
	mlx_key_hook(data->window, handle_keypress, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}
