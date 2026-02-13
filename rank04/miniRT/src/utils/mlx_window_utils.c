/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:32:45 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:21 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	close_window(t_data *data)
{
	if (data->mlx && data->window)
	{
		mlx_destroy_image(data->mlx, data->img->image);
		mlx_destroy_image(data->mlx, data->p_img->image);
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
		free_data(data);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307 || keysym == 53)
	{
		mlx_destroy_image(data->mlx, data->img->image);
		mlx_destroy_image(data->mlx, data->p_img->image);
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
		free_data(data);
		exit(0);
	}
	return (0);
}
