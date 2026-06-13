/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:50:05 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/12 14:50:07 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "rt_math.h"
#include <math.h>

t_vec4	vec4_mul(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	res.w = a.w;
	return (res);
}

int	vec4_to_int(t_vec4 c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmin(fmax(c.x, 0.0), 1.0) * 255.0);
	g = (int)(fmin(fmax(c.y, 0.0), 1.0) * 255.0);
	b = (int)(fmin(fmax(c.z, 0.0), 1.0) * 255.0);
	return ((r << 16) | (g << 8) | b);
}

t_vec4	norm_color(t_color c)
{
	return ((t_vec4){.x = c.x / 255.0, .y = c.y / 255.0, .z = c.z / 255.0,
		.w = 0.0});
}
