/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:36:24 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:30 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	get_ambient(t_data *data, t_color base_color)
{
	t_color	ambient;

	ambient.r = base_color.r * (data->ambient->rgb->r / 255.0)
		* data->ambient->lighting_ratio;
	ambient.g = base_color.g * (data->ambient->rgb->g / 255.0)
		* data->ambient->lighting_ratio;
	ambient.b = base_color.b * (data->ambient->rgb->b / 255.0)
		* data->ambient->lighting_ratio;
	return (ambient);
}

t_color	get_final(t_color ambient, t_color lighting)
{
	t_color	final;

	final.r = fmin(ambient.r + lighting.r, 255);
	final.g = fmin(ambient.g + lighting.g, 255);
	final.b = fmin(ambient.b + lighting.b, 255);
	return (final);
}

int	find_closest_hit(t_ray ray, t_data *data)
{
	int	found;

	found = 0;
	data->hit_record->t = __DBL_MAX__;
	if (find_nearest_sphere(ray, data))
		found = 1;
	if (find_nearest_plane(ray, data))
		found = 1;
	if (find_nearest_cylinder(ray, data))
		found = 1;
	return (found);
}

t_color	trace_ray(t_ray ray, t_data *data, int depth)
{
	t_color	base_color;
	t_color	ambient;
	t_color	lighting;
	t_color	final;

	base_color = (t_color){0, 0, 0};
	if (!find_closest_hit(ray, data))
		return (base_color);
	base_color = int_to_color(data->hit_record->color);
	ambient = get_ambient(data, base_color);
	lighting = get_lighting(data, *data->hit_record, base_color, ray);
	final = get_final(ambient, lighting);
	return (do_reflection(depth, ray, data, final));
}
