/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:10:56 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:56 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	display_sphere_obj_data(t_sphere *sp);

int	create_cylinder(t_data *data, char **args)
{
	data->cylinder[data->objects->cylinder_index] = create_cylinder_obj(args);
	if (!data->cylinder[data->objects->cylinder_index])
		return (1);
	display_cylinder_obj_data(data->cylinder[data->objects->cylinder_index]);
	data->objects->cylinder_index++;
	return (0);
}

int	create_plane(t_data *data, char **args)
{
	data->plane[data->objects->plane_index] = create_plane_obj(args);
	if (!data->plane[data->objects->plane_index])
		return (1);
	display_plane_obj_data(data->plane[data->objects->plane_index]);
	data->objects->plane_index++;
	return (0);
}

int	create_sphere(t_data *data, char **args)
{
	data->sphere[data->objects->sphere_index] = create_sphere_obj(args);
	if (!data->sphere[data->objects->sphere_index])
		return (1);
	display_sphere_obj_data(data->sphere[data->objects->sphere_index]);
	data->objects->sphere_index++;
	return (0);
}
