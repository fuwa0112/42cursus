/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:44:21 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:35 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	init_viewport(t_data *data)
{
	t_vec3	world_up;
	double	fov_rad;
	double	aspect_ratio;

	if (!data || !data->camera || !data->img)
		return (1);
	data->viewport = malloc(sizeof(t_viewport));
	if (!data->viewport || !data->camera->position || !data->camera->oriention)
		return (1);
	aspect_ratio = (double)data->img->img_w / data->img->img_h;
	if (aspect_ratio <= 0.0)
		return (1);
	fov_rad = tan((data->camera->fov / 2 * PI / 180.0));
	data->viewport->viewport_h = 2.0 * fov_rad;
	data->viewport->viewport_w = data->viewport->viewport_h * aspect_ratio;
	data->viewport->forward = vec_normalize(*(data->camera->oriention));
	world_up = (t_vec3){0, 1, 0};
	if (fabs(vec_dot(data->viewport->forward, world_up)) > 0.999)
		world_up = (t_vec3){0, 0, 1};
	init_viewport_pixel(data, world_up);
	return (0);
}

void	init_viewport_pixel(t_data *data, t_vec3 world_up)
{
	t_vec3	half_horiz;
	t_vec3	half_vert;

	if (!data || !data->viewport || !data->img)
		return ;
	data->viewport->center = vec_add(*(data->camera->position),
			data->viewport->forward);
	data->viewport->right = vec_normalize(vec_cross(world_up,
				data->viewport->forward));
	data->viewport->up = vec_normalize(vec_cross(data->viewport->forward,
				data->viewport->right));
	half_horiz = vec_mul(data->viewport->right, data->viewport->viewport_w
			/ 2.0);
	half_vert = vec_mul(data->viewport->up, data->viewport->viewport_h / 2.0);
	data->viewport->top_left = vec_sub(vec_sub(data->viewport->center,
				half_horiz), half_vert);
	data->viewport->pixel_u = vec_div(vec_mul(half_horiz, 2), data->img->img_w);
	data->viewport->pixel_v = vec_div(vec_mul(half_vert, 2), data->img->img_h);
	data->viewport->pixel_00 = vec_add(data->viewport->top_left,
			vec_add(vec_mul(data->viewport->pixel_u, 0.5),
				vec_mul(data->viewport->pixel_v, 0.5)));
}
