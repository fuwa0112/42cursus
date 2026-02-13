/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:07:39 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:27 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	random_double(void)
{
	return ((double)rand() / ((double)(RAND_MAX) + 1));
}

double	random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_unit_vector(void)
{
	t_vec3	v;
	double	lensq;

	while (1)
	{
		v.x = random_double_range(-1.0, 1.0);
		v.y = random_double_range(-1.0, 1.0);
		v.z = random_double_range(-1.0, 1.0);
		lensq = vec_dot(v, v);
		if (1e-160 < lensq && lensq <= 1.0)
		{
			return (vec_div(v, sqrt(lensq)));
		}
	}
}

t_vec3	random_on_hemisphere(t_vec3 normal)
{
	t_vec3	on_unit_sphere;

	on_unit_sphere = random_unit_vector();
	if (vec_dot(on_unit_sphere, normal) < 0.0)
	{
		vec_mul(on_unit_sphere, -1.0);
	}
	return (on_unit_sphere);
}
