/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:51:19 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:51:20 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef struct s_ambient
{
	double	lighting_ratio;
	t_color	*rgb;
}			t_ambient;

typedef struct s_camera
{
	t_vec3	*position;
	t_vec3	*oriention;
	double	fov;
}			t_camera;

typedef struct s_light
{
	t_vec3	*position;
	double	brightness;
	t_color	*rgb;
}			t_light;

typedef struct s_sphere
{
	t_vec3	*position;
	double	diameter;
	double	radius;
	t_color	*rgb;
	double	reflection;
	double	spec;
}			t_sphere;

typedef struct s_plane
{
	t_vec3	*position;
	t_vec3	*oriention;
	t_color	*rgb;
	double	spec;
}			t_plane;

typedef struct s_cylinder
{
	t_vec3	*position;
	t_vec3	*oriention;
	double	diameter;
	double	radius;
	double	height;
	t_color	*rgb;
	t_vec3	top_center;
	t_vec3	bottom_center;
	double	dot_d;
	double	dot_oc;
	double	spec;
	double	reflection;
}			t_cylinder;

typedef struct s_object_count
{
	int		ambient_count;
	int		camera_count;
	int		light_count;
	int		light_index;
	int		sphere_count;
	int		sphere_index;
	int		plane_count;
	int		plane_index;
	int		cylinder_count;
	int		cylinder_index;
}			t_object_count;

t_ambient	*create_ambient_obj(char **args);
t_camera	*create_camera_obj(char **args);
t_cylinder	*create_cylinder_obj(char **args);
t_light		*create_light_obj(char **args);
t_sphere	*create_sphere_obj(char **args);
t_plane		*create_plane_obj(char **args);

#endif
