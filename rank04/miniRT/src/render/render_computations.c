/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_computations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:32:50 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:03 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		check_c_pos(const t_data *data, t_camera camera, t_light light);

void	compute_light_dir(t_vec3 *light_dir, double *light_dist, t_light light,
		t_vec3 hit_point)
{
	*light_dir = vec_sub(*light.position, hit_point);
	*light_dist = vec_length(*light_dir);
	*light_dir = vec_normalize(*light_dir);
}

t_color	compute_diffuse(t_hit hit, t_vec3 light_dir, t_color base_color,
		t_light *light)
{
	double	intensity;
	t_color	result;

	intensity = vec_dot(hit.normal, light_dir);
	if (intensity > 0.0)
	{
		result.r = base_color.r * (light->rgb->r / 255.0) * intensity
			* light->brightness;
		result.g = base_color.g * (light->rgb->g / 255.0) * intensity
			* light->brightness;
		result.b = base_color.b * (light->rgb->b / 255.0) * intensity
			* light->brightness;
	}
	else
	{
		result.r = 0;
		result.g = 0;
		result.b = 0;
	}
	return (result);
}

t_color	compute_specular(t_hit hit, t_vec3 light_dir, t_ray ray, t_light *light)
{
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec_angle;
	double	intensity;
	t_color	specular;

	if (SPECULAR_POWER == 0)
		return ((t_color){0, 0, 0});
	view_dir = vec_normalize(vec_mul(ray.direction, -1));
	reflect_dir = vec_reflect(vec_mul(light_dir, -1), hit.normal);
	spec_angle = fmax(vec_dot(view_dir, reflect_dir), 0.0);
	intensity = pow(spec_angle, hit.spec) * light->brightness;
	specular.r = intensity * (light->rgb->r / 255);
	specular.g = intensity * (light->rgb->g / 255);
	specular.b = intensity * (light->rgb->b / 255);
	return (specular);
}

t_color	do_reflection(int depth, t_ray ray, t_data *data, t_color final)
{
	t_vec3	reflect_dir;
	t_ray	reflect_ray;
	t_color	reflect_color;
	t_hit	hit;

	hit = *data->hit_record;
	if (depth > 0 && hit.reflectivity > 0.0)
	{
		reflect_dir = vec_reflect(ray.direction, hit.normal);
		reflect_dir = vec_normalize(reflect_dir);
		reflect_ray.origin = vec_add(hit.point, vec_mul(hit.normal, EPSILON));
		reflect_ray.direction = reflect_dir;
		reflect_color = trace_ray(reflect_ray, data, depth - 1);
		final = color_blend(final, reflect_color, hit.reflectivity);
	}
	return (final);
}

t_color	get_lighting(t_data *data, t_hit hit, t_color base_color, t_ray ray)
{
	t_color	diffuse;
	t_color	specular;
	t_vec3	l_dir;
	double	l_dist;
	int		j;

	j = -1;
	diffuse = (t_color){0, 0, 0};
	specular = (t_color){0, 0, 0};
	while (++j < data->objects->light_count)
	{
		if (check_light_positions(data->objects, data->light[j], data)
			&& check_c_pos(data, *data->camera, *data->light[j]))
		{
			compute_light_dir(&l_dir, &l_dist, *data->light[j], hit.point);
			if (!check_all_shadows(data, l_dist, l_dir))
			{
				diffuse = color_add(diffuse, compute_diffuse(hit, l_dir,
							base_color, data->light[j]));
				specular = color_add(specular, compute_specular(hit, l_dir, ray,
							data->light[j]));
			}
		}
	}
	return (color_add(diffuse, specular));
}
