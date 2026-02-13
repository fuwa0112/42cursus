/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:51:22 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:51:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_viewport
{
	double	viewport_w;
	double	viewport_h;
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	center;
	t_vec3	top_left;
	t_vec3	pixel_u;
	t_vec3	pixel_v;
	t_vec3	pixel_00;
}			t_viewport;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}			t_ray;

typedef struct s_t
{
	double	t1;
	double	t2;
}			t_t;
typedef struct s_hit
{
	double	t;
	t_t		t_values;
	t_vec3	point;
	t_vec3	normal;
	int		color;
	double	reflectivity;
	double	spec;
}			t_hit;

#endif
