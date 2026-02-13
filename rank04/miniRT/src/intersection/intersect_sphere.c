/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:45:03 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:54 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	get_discriminant(t_ray ray, t_sphere *sphere, t_vec3 oc)
{
	double	radius;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	radius = sphere->diameter / 2.0;
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}

double	get_t(double discriminant, t_ray ray, t_vec3 oc, double max_t)
{
	double	sqrt_disc;
	double	t1;
	double	t2;
	double	a;

	a = vec_dot(ray.direction, ray.direction);
	if (discriminant < 0)
		return (__DBL_MAX__);
	sqrt_disc = sqrt(discriminant);
	t1 = (-2.0 * vec_dot(oc, ray.direction) - sqrt_disc) / (2.0 * a);
	t2 = (-2.0 * vec_dot(oc, ray.direction) + sqrt_disc) / (2.0 * a);
	if (t1 >= EPSILON && t1 < max_t)
		return (t1);
	if (t2 >= EPSILON && t2 < max_t)
		return (t2);
	return (__DBL_MAX__);
}

int	intersect_sphere(t_ray ray, t_sphere *sphere, t_hit *hit, double max_t)
{
	double	discriminant;
	t_vec3	oc;
	double	t;

	oc = vec_sub(ray.origin, *sphere->position);
	discriminant = get_discriminant(ray, sphere, oc);
	if (discriminant < 0)
		return (0);
	t = get_t(discriminant, ray, oc, max_t);
	if (t == __DBL_MAX__)
		return (0);
	hit->t = t;
	hit->point = vec_add(ray.origin, vec_mul(ray.direction, t));
	hit->normal = vec_normalize(vec_sub(hit->point, *sphere->position));
	hit->color = color_to_int(*sphere->rgb);
	hit->reflectivity = sphere->reflection;
	hit->spec = sphere->spec;
	return (1);
}

int	find_nearest_sphere(t_ray ray, t_data *data)
{
	t_hit	temp_hit;
	int		found;
	int		i;

	found = 0;
	i = 0;
	temp_hit = (t_hit){0};
	temp_hit.t = __DBL_MAX__;
	while (data->sphere[i])
	{
		if (intersect_sphere(ray, data->sphere[i], &temp_hit,
				data->hit_record->t))
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
