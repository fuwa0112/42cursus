/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:24:09 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:51 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	intersect_plane(t_ray *ray, t_plane *plane, t_hit *hit)
{
	double	denominator;
	double	t;

	denominator = vec_dot(*plane->oriention, ray->direction);
	if (fabs(denominator) < 1e-4)
		t = __DBL_MAX__;
	t = vec_dot(vec_sub(*plane->position, ray->origin), *plane->oriention)
		/ denominator;
	if (t < 0)
		t = __DBL_MAX__;
	hit->t = t;
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, t));
	hit->normal = *plane->oriention;
	hit->color = color_to_int(*plane->rgb);
	hit->reflectivity = 0.0;
	hit->spec = plane->spec;
	return (1);
}

int	find_nearest_plane(t_ray ray, t_data *data)
{
	t_hit	temp_hit;
	int		found;
	int		i;

	found = 0;
	i = 0;
	while (data->plane[i])
	{
		if (intersect_plane(&ray, data->plane[i], &temp_hit))
		{
			if (temp_hit.t < data->hit_record->t)
			{
				*data->hit_record = temp_hit;
				found = 1;
			}
		}
		i++;
	}
	return (found);
}
