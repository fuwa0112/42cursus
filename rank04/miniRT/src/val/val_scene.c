/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 12:48:47 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/13 23:45:02 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_valid_ambient(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || arr[3])
		return (0);
	if (!is_valid_ratio(arr[1]) || !is_valid_color(arr[2]))
		return (0);
	return (1);
}

int	is_valid_camera(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3] || arr[4])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_normalized_vector(arr[2])
		|| !is_valid_fov(arr[3]))
		return (0);
	return (1);
}

int	is_valid_light(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3] || arr[4])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_ratio(arr[2])
		|| !is_valid_color(arr[3]))
		return (0);
	return (1);
}

int	has_enough_elements(t_obj_count obj_count)
{
	char	has_error;

	has_error = 0;
	if (obj_count.ambient != 1 && ++has_error)
		show_error("It should have one ambient");
	else if (obj_count.camera != 1 && ++has_error)
		show_error("It should have one camera");
	else if (obj_count.light != 1 && ++has_error)
		show_error("It should have one light");
	else if (obj_count.obj == 0 && ++has_error)
		show_error("No objects in the scene");
	return (has_error == 0);
}
