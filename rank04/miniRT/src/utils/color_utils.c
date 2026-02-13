/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 02:30:46 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:51 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmin(color.r, 255));
	g = (int)(fmin(color.g, 255));
	b = (int)(fmin(color.b, 255));
	return ((r << 16) | (g << 8) | b);
}

t_vec3	color_to_vec3(t_color color)
{
	t_vec3	out;

	out.x = (double)(fmin(color.r, 255)) / 255.0;
	out.y = (double)(fmin(color.g, 255)) / 255.0;
	out.z = (double)(fmin(color.b, 255)) / 255.0;
	return (out);
}

t_color	int_to_color(int color)
{
	t_color	out;

	out.r = (color >> 16) & 255;
	out.g = (color >> 8) & 255;
	out.b = color & 255;
	return (out);
}

t_vec3	int_to_vec3(int color)
{
	t_color	col;
	t_vec3	out;

	col = int_to_color(color);
	out.x = (double)(col.r) / 255.0;
	out.y = (double)(col.g) / 255.0;
	out.z = (double)(col.b) / 255.0;
	return (out);
}

int	vec3_to_int(t_vec3 vec)
{
	t_color	col;

	col = vec3_to_color(vec);
	return (color_to_int(col));
}
