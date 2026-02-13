/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 02:19:49 by lshein            #+#    #+#             */
/*   Updated: 2025/07/16 04:23:18 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	random_double(void)
{
	return ((double)rand() / ((double)(RAND_MAX) + 1));
}

t_vec3	sample_square(void)
{
	return (vec(random_double() - 0.5, random_double() - 0.5, 0));
}

t_ray	get_ray(t_data *data, int x, int y)
{
	t_vec3	offset;
	t_vec3	pixel_position;
	t_vec3	direction;
	t_ray	ray;

	if (!data || !data->camera || !data->viewport || !data->img)
		return ((t_ray){vec(0, 0, 0), vec(0, 0, 0)});
	offset = sample_square();
	pixel_position = vec_add(data->viewport->pixel_00,
			vec_add(vec_mul(data->viewport->pixel_u, x + offset.x),
				vec_mul(data->viewport->pixel_v, data->img->img_h - 1 - y
					+ offset.y)));
	direction = vec_normalize(vec_sub(pixel_position, *data->camera->position));
	ray.origin = *data->camera->position;
	ray.direction = direction;
	return (ray);
}
