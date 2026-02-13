/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_position_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:49:40 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:42 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int			is_light_on_plane(t_light light, t_plane plane);

static int	is_camera_in_sphere(const t_data *data, t_camera camera)
{
	int		i;
	double	dist;

	i = 0;
	while (i < data->objects->sphere_count)
	{
		dist = vec_length(vec_sub(*camera.position,
					*data->sphere[i]->position));
		if (dist < data->sphere[i]->radius)
			return (1);
		i++;
	}
	return (0);
}

static int	is_camera_in_cylinder(const t_data *data, t_camera camera)
{
	int		i;
	t_vec3	to_cam;
	double	proj;
	t_vec3	radial;

	i = 0;
	while (i < data->objects->cylinder_count)
	{
		to_cam = vec_sub(*camera.position, *data->cylinder[i]->position);
		proj = vec_dot(to_cam, *data->cylinder[i]->oriention);
		if (proj < -(data->cylinder[i]->height / 2.0) / 2.0
			|| proj > (data->cylinder[i]->height / 2.0) / 2.0)
		{
			i++;
			continue ;
		}
		radial = vec_sub(to_cam, vec_mul(*data->cylinder[i]->oriention, proj));
		if (vec_length(radial) < data->cylinder[i]->radius)
			return (1);
		i++;
	}
	return (0);
}

int	check_c_pos(const t_data *data, t_camera camera, t_light light)
{
	int	i;

	i = 0;
	while (i < data->objects->plane_count)
		if (is_light_on_plane(light, *data->plane[i++]))
			return (1);
	if (is_camera_in_sphere(data, camera))
		return (0);
	if (is_camera_in_cylinder(data, camera))
		return (0);
	return (1);
}
