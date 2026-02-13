/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 02:23:09 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:18:42 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	cap_intersection(t_ray ray, t_cylinder *cylinder, t_vec3 cap_center,
		t_t *hit_t)
{
	double	denom;
	double	t_cap;
	t_vec3	hit_point;
	t_vec3	dist;

	denom = vec_dot(ray.direction, *cylinder->oriention);
	if (fabs(denom) < 1e-4)
		return ;
	t_cap = vec_dot(vec_sub(cap_center, ray.origin), *cylinder->oriention)
		/ denom;
	if (t_cap <= 0)
		return ;
	hit_point = vec_add(ray.origin, vec_mul(ray.direction, t_cap));
	dist = vec_sub(hit_point, cap_center);
	if (vec_dot(dist, dist) <= (cylinder->diameter / 2.0) * (cylinder->diameter
			/ 2.0))
	{
		if (t_cap < hit_t->t1)
			hit_t->t1 = t_cap;
		else if (t_cap < hit_t->t2)
			hit_t->t2 = t_cap;
	}
}

void	check_caps(t_ray *ray, t_cylinder *cylinder, t_t *hit_t)
{
	t_vec3	top_center;
	t_vec3	bottom_center;

	top_center = vec_add(*cylinder->position, vec_mul(*cylinder->oriention,
				cylinder->height / 2.0));
	bottom_center = vec_sub(*cylinder->position, vec_mul(*cylinder->oriention,
				cylinder->height / 2.0));
	cap_intersection(*ray, cylinder, top_center, hit_t);
	cap_intersection(*ray, cylinder, bottom_center, hit_t);
}

void	is_within_height(t_t *t_values, t_cylinder *cylinder)
{
	double	p1;
	double	p2;

	p1 = cylinder->dot_oc + t_values->t1 * cylinder->dot_d;
	p2 = cylinder->dot_oc + t_values->t2 * cylinder->dot_d;
	if (!(t_values->t1 > 0 && p1 >= -cylinder->height / 2.0
			&& p1 <= cylinder->height / 2.0))
		t_values->t1 = __DBL_MAX__;
	if (!(t_values->t2 > 0 && p2 >= -cylinder->height / 2.0
			&& p2 <= cylinder->height / 2.0))
		t_values->t2 = __DBL_MAX__;
}

double	discriminant_cy(t_ray *ray, t_cylinder *cylinder, double *a, double *b)
{
	t_vec3	oc;
	t_vec3	axis_d;
	t_vec3	axis_oc;
	double	discriminant;
	double	c;

	oc = vec_sub(ray->origin, *cylinder->position);
	cylinder->dot_d = vec_dot(ray->direction, *cylinder->oriention);
	cylinder->dot_oc = vec_dot(oc, *cylinder->oriention);
	axis_d = vec_sub(ray->direction, vec_mul(*cylinder->oriention,
				cylinder->dot_d));
	axis_oc = vec_sub(oc, vec_mul(*cylinder->oriention, cylinder->dot_oc));
	*a = vec_dot(axis_d, axis_d);
	*b = 2.0 * vec_dot(axis_d, axis_oc);
	c = vec_dot(axis_oc, axis_oc) - (cylinder->diameter / 2.0)
		* (cylinder->diameter / 2.0);
	discriminant = (*b) * (*b) - 4.0 * (*a) * c;
	return (discriminant);
}
