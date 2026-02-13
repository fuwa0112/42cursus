/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_position_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:09:45 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:15 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	is_light_in_sphere(t_light light, t_sphere sphere)
{
	double	dist;

	dist = vec_length(vec_sub(*light.position, *sphere.position));
	return (dist < sphere.radius);
}

int	is_light_in_cylinder(t_light light, t_cylinder cylinder)
{
	t_vec3	to_light;
	double	proj;
	t_vec3	radial;

	to_light = vec_sub(*light.position, *cylinder.position);
	proj = vec_dot(to_light, *cylinder.oriention);
	if (proj < -(cylinder.height / 2) || proj > (cylinder.height / 2))
		return (0);
	radial = vec_sub(to_light, vec_mul(*cylinder.oriention, proj));
	return (vec_length(radial) < cylinder.radius);
}

int	is_light_on_plane(t_light light, t_plane plane)
{
	t_vec3	to_light;

	to_light = vec_sub(*light.position, *plane.position);
	return (fabs(vec_dot(to_light, *plane.oriention)) < 1e-4);
}

int	check_light_positions(t_object_count *scene, t_light *light, t_data *data)
{
	int	j;

	j = 0;
	if (!scene || !data || !light)
		return (0);
	while (j < scene->sphere_count)
		if (is_light_in_sphere(*light, *data->sphere[j++]))
			return (0);
	j = 0;
	while (j < scene->cylinder_count)
		if (is_light_in_cylinder(*light, *data->cylinder[j++]))
			return (0);
	j = 0;
	while (j < scene->plane_count)
		if (is_light_on_plane(*light, *data->plane[j++]))
			return (0);
	return (1);
}
