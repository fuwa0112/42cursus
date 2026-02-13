/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:29:11 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:48 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	intersect_cylinder(t_ray *ray, t_cylinder *cylinder, t_hit *hit)
{
	double	discriminant;
	t_t		t_values;
	double	sqrt_disc;
	double	a;
	double	b;

	discriminant = discriminant_cy(ray, cylinder, &a, &b);
	t_values.t1 = __DBL_MAX__;
	t_values.t2 = __DBL_MAX__;
	if (discriminant < 0)
	{
		hit->t_values = t_values;
		return (1);
	}
	sqrt_disc = sqrt(discriminant);
	t_values.t1 = (-b - sqrt_disc) / (2.0 * a);
	t_values.t2 = (-b + sqrt_disc) / (2.0 * a);
	is_within_height(&t_values, cylinder);
	check_caps(ray, cylinder, &t_values);
	hit->t_values = t_values;
	hit->reflectivity = cylinder->reflection;
	hit->spec = cylinder->spec;
	return (1);
}

void	get_cylinder_normal(t_cylinder *cylinder, t_hit *hit)
{
	t_vec3	to_center;
	double	projection;

	to_center = vec_sub(hit->point, *cylinder->position);
	projection = vec_dot(to_center, *cylinder->oriention);
	if (fabs(projection - cylinder->height / 2.0) < 1e-4)
		hit->normal = *cylinder->oriention;
	else if (fabs(projection + cylinder->height / 2.0) < 1e-4)
		hit->normal = vec_mul(*cylinder->oriention, -1);
	else
	{
		hit->normal = vec_sub(to_center, vec_mul(*cylinder->oriention,
					projection));
		hit->normal = vec_normalize(hit->normal);
	}
}

void	cylinder_hit(t_cylinder *cylinder, t_ray *ray, double t, t_hit *hit)
{
	hit->t = t;
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, t));
	get_cylinder_normal(cylinder, hit);
	hit->color = color_to_int(*cylinder->rgb);
	hit->spec = cylinder->spec;
	hit->reflectivity = cylinder->reflection;
}

int	check_cylinder_hit(t_cylinder *cylinder, t_ray *ray, double t,
		t_hit *hit_record)
{
	if (t >= 0.0001 && t <= __DBL_MAX__ && t < hit_record->t)
	{
		cylinder_hit(cylinder, ray, t, hit_record);
		return (1);
	}
	return (0);
}

int	find_nearest_cylinder(t_ray ray, t_data *data)
{
	t_hit	temp_hit;
	int		found;
	int		i;

	found = 0;
	i = 0;
	temp_hit = (t_hit){0};
	temp_hit.t = __DBL_MAX__;
	while (data->cylinder[i])
	{
		if (intersect_cylinder(&ray, data->cylinder[i], &temp_hit))
		{
			found |= check_cylinder_hit(data->cylinder[i], &ray,
					temp_hit.t_values.t1, data->hit_record);
			found |= check_cylinder_hit(data->cylinder[i], &ray,
					temp_hit.t_values.t2, data->hit_record);
		}
		i++;
	}
	return (found);
}
