/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:55:23 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:59 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	create_amb(t_data *data, char **args)
{
	if (data->ambient)
		free(data->ambient);
	data->ambient = create_ambient_obj(args);
	if (!data->ambient)
		return (1);
	display_ambient_obj_data(data->ambient);
	return (0);
}

int	create_cam(t_data *data, char **args)
{
	if (data->camera)
		free(data->camera);
	data->camera = create_camera_obj(args);
	if (!data->camera)
		return (1);
	display_camera_obj_data(data->camera);
	return (0);
}

int	create_light(t_data *data, char **args)
{
	data->light[data->objects->light_index] = create_light_obj(args);
	if (!data->light[data->objects->light_index])
		return (1);
	display_light_obj_data(data->light[data->objects->light_index]);
	data->objects->light_index++;
	return (0);
}
