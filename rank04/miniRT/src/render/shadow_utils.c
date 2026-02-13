/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:28:29 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:33 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	check_sphere_shadow(t_ray shadow_ray, t_data *data, double light_dist,
		int *shadow)
{
	t_hit	shadow_hit;
	int		i;

	i = 0;
	shadow_hit = (t_hit){0};
	shadow_hit.t = __DBL_MAX__;
	while (data->sphere[i])
	{
		if (intersect_sphere(shadow_ray, data->sphere[i], &shadow_hit,
				light_dist) && shadow_hit.t > EPSILON
			&& shadow_hit.t < light_dist)
		{
			*shadow = 1;
			return ;
		}
		i++;
	}
}

void	check_plane_shadow(t_ray shadow_ray, t_data *data, double light_dist,
		int *shadow)
{
	t_hit	shadow_hit;
	int		i;

	i = 0;
	shadow_hit = (t_hit){0};
	shadow_hit.t = __DBL_MAX__;
	while (data->plane[i])
	{
		if (intersect_plane(&shadow_ray, data->plane[i], &shadow_hit)
			&& shadow_hit.t > EPSILON && shadow_hit.t < light_dist)
		{
			*shadow = 1;
			return ;
		}
		i++;
	}
}

void	check_cylinder_shadow(t_ray shadow_ray, t_data *data, double light_dist,
		int *shadow)
{
	t_hit	shadow_hit;
	int		i;

	i = 0;
	shadow_hit = (t_hit){0};
	shadow_hit.t = __DBL_MAX__;
	while (data->cylinder[i])
	{
		if (intersect_cylinder(&shadow_ray, data->cylinder[i], &shadow_hit)
			&& shadow_hit.t > EPSILON && shadow_hit.t < light_dist)
		{
			*shadow = 1;
			return ;
		}
		i++;
	}
}

int	check_all_shadows(t_data *data, double light_dist, t_vec3 light_dir)
{
	int		shadow;
	t_ray	shadow_ray;

	shadow = 0;
	shadow_ray.origin = data->hit_record->point;
	shadow_ray.direction = light_dir;
	check_sphere_shadow(shadow_ray, data, light_dist, &shadow);
	check_plane_shadow(shadow_ray, data, light_dist, &shadow);
	check_cylinder_shadow(shadow_ray, data, light_dist, &shadow);
	return (shadow);
}
