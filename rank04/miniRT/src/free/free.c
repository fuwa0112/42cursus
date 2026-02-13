/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:03:35 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:28 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_mlx(t_data *data)
{
	if (data->mlx && data->window)
	{
		if (data->img && data->img->image)
			mlx_destroy_image(data->mlx, data->img->image);
		if (data->p_img && data->p_img->image)
			mlx_destroy_image(data->mlx, data->p_img->image);
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->img)
	{
		free(data->img);
		data->img = NULL;
	}
	if (data->p_img)
	{
		free(data->p_img);
		data->p_img = NULL;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
		free_mlx(data);
	if (data->ambient)
		free_ambient(data->ambient);
	if (data->camera)
		free_camera(data->camera);
	if (data->light)
		free_light_arr(data->light);
	if (data->sphere)
		free_sphere_arr(data->sphere, data);
	if (data->plane)
		free_plane_arr(data->plane);
	if (data->cylinder)
		free_cylinder_arr(data->cylinder);
	if (data->hit_record)
		free(data->hit_record);
	if (data->viewport)
		free(data->viewport);
	if (data->objects)
		free(data->objects);
	free(data);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines && lines[i])
		free(lines[i++]);
	free(lines);
}
