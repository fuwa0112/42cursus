/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:34:45 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 14:07:06 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	bzero_objs(t_data *data)
{
	if (data->camera)
		ft_bzero(data->camera, sizeof(t_camera));
	if (data->sphere)
		ft_bzero(data->sphere, sizeof(t_sphere *) * (data->objects->sphere_count
				+ 1));
	if (data->cylinder)
		ft_bzero(data->cylinder, sizeof(t_cylinder *)
			* (data->objects->cylinder_count + 1));
	if (data->plane)
		ft_bzero(data->plane, sizeof(t_plane *) * (data->objects->plane_count
				+ 1));
	if (data->light)
		ft_bzero(data->light, sizeof(t_light *) * (data->objects->light_count
				+ 1));
	if (data->ambient)
		ft_bzero(data->ambient, sizeof(t_ambient));
}

int	init_objects(t_data *data)
{
	if (data->objects->ambient_count != 1 || data->objects->camera_count != 1
		|| data->objects->light_count < 1)
	{
		ft_putstr_fd("Error\nMinimum 1light,1 Camera and 1 Ambient!!\n", 2);
		return (1);
	}
	data->hit_record = malloc(sizeof(t_hit));
	if (!data->hit_record)
		return (1);
	data->hit_record->t = __DBL_MAX__;
	data->hit_record->reflectivity = 0.0;
	data->ambient = malloc(sizeof(t_ambient));
	data->camera = malloc(sizeof(t_camera));
	data->light = malloc(sizeof(t_light *) * (data->objects->light_count + 1));
	data->sphere = malloc(sizeof(t_sphere *) * (data->objects->sphere_count
				+ 1));
	data->plane = malloc(sizeof(t_plane *) * (data->objects->plane_count + 1));
	data->cylinder = malloc(sizeof(t_cylinder *)
			* (data->objects->cylinder_count + 1));
	if (!data->ambient || !data->camera || !data->light || !data->sphere
		|| !data->plane || !data->cylinder)
		return (1);
	bzero_objs(data);
	return (0);
}

int	init_object_counts(t_data *data)
{
	data->objects = malloc(sizeof(t_object_count));
	if (!data->objects)
		return (1);
	data->objects->ambient_count = 0;
	data->objects->camera_count = 0;
	data->objects->light_count = 0;
	data->objects->sphere_count = 0;
	data->objects->plane_count = 0;
	data->objects->cylinder_count = 0;
	data->objects->light_index = 0;
	data->objects->cylinder_index = 0;
	data->objects->plane_index = 0;
	data->objects->sphere_index = 0;
	return (0);
}

int	init_image(int width, void *mlx, t_image *img)
{
	if (!img)
		return (1);
	img->img_w = W_W;
	img->img_h = W_H;
	if (img->img_h < 1)
		img->img_h = 1;
	img->image = mlx_new_image(mlx, width, img->img_h);
	img->addr = mlx_get_data_addr(img->image, &img->bpp, &img->line_size,
			&img->endian);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->img = malloc(sizeof(t_image));
	data->p_img = malloc(sizeof(t_image));
	if (!data->img || !data->p_img)
		return (free_data(data), 1);
	if (init_image(W_W, data->mlx, data->img) == 1)
		return (free_data(data), 1);
	if (init_image(W_W, data->mlx, data->p_img) == 1)
		return (free_data(data), 1);
	data->window = mlx_new_window(data->mlx, W_W, W_H, "MINIRT");
	if (!data->window)
		return (1);
	return (0);
}
