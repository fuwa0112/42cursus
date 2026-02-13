/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:13:40 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:51 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return (vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y
			* b.x));
}

double	vec_length(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	len;

	len = vec_length(v);
	return (vec(v.x / len, v.y / len, v.z / len));
}

t_vec3	vec_div(t_vec3 v, double s)
{
	return (vec(v.x / s, v.y / s, v.z / s));
}
