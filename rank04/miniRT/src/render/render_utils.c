/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:56:26 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:27 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	put_pixel(t_data *data, int color, int is_image, int xy[])
{
	char	*dst;

	if (is_image)
		dst = data->img->addr + (xy[1] * data->img->line_size + xy[0]
				* (data->img->bpp / 8));
	else
		dst = data->p_img->addr + (xy[1] * data->p_img->line_size + xy[0]
				* (data->p_img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_vec3	vec_reflect(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_mul(n, 2.0 * vec_dot(v, n))));
}

t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r + b.r;
	result.g = a.g + b.g;
	result.b = a.b + b.b;
	return (result);
}

t_color	color_blend(t_color base, t_color overlay, double alpha)
{
	t_color	result;

	result.r = (1 - alpha) * base.r + alpha * overlay.r;
	result.g = (1 - alpha) * base.g + alpha * overlay.g;
	result.b = (1 - alpha) * base.b + alpha * overlay.b;
	return (result);
}
