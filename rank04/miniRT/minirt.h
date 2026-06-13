/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/14 00:52:37 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# include "src/libft/inc/libft.h"
# include "mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define EPSILON 1e-4

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_mat4
{
	double	m[4][4];
}	t_mat4;

typedef struct s_ray
{
	t_vec4	dir;
	t_vec4	orig;
	double	t;
}	t_ray;

typedef t_vec4	t_color;

typedef struct s_ambient
{
	double	lightness;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec4	origin;
	t_vec4	dir;
	t_vec4	right;
	t_vec4	up;
	double	fov_scale;
	double	aspect;
}	t_camera;

typedef struct s_light
{
	t_vec4	origin;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_specular
{
	double	index;
	double	strenght;
	t_color	color;
}	t_specular;

typedef struct s_material
{
	t_color		color;
	t_specular	specular;
	double		reflect;
}	t_material;

typedef struct s_obj
{
	t_mat4	mat;
	t_vec4	coordinate;
	t_vec4	orientation;
	double	min;
	double	max;
	t_color	color;
}	t_obj;

typedef enum e_surface_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_surface_type;

typedef struct s_surface
{
	t_obj			obj;
	t_surface_type	type;
	unsigned char	is_bounded;
}	t_surface;

typedef struct s_surface_parameters
{
	t_vec4			coordinate;
	t_vec4			orientation;
	t_vec4			w;
	t_vec4			l;
	double			diameter;
	double			height;
	t_surface_type	type;
	t_color			color;
	unsigned char	is_bounded : 1;
}	t_surface_parameters;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient		ambient;
	t_specular		specular;
	t_list			*objs;
	t_light			*light;
	t_surface		*surfaces;
	unsigned int	idx_obj;
	unsigned int	num_objs;
	unsigned int	num_lights;
}	t_scene;

typedef struct s_img_buffer
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		pixel_size;
}	t_img_buffer;

typedef struct s_window
{
	int				width;
	int				height;
	void			*mlx;
	void			*x_window;
	t_img_buffer	img;
}	t_window;

typedef struct s_env
{
	t_window	window;
	t_scene		scene;
}	t_env;

typedef struct s_light_componets_params
{
	t_vec4	n;
	t_vec4	hit_p;
	double	shadow;
}	t_light_componets_params;

typedef struct s_hash_item_parser
{
	char	*key;
	void	(*parse)(char **, t_scene *);
}	t_hash_item_parser;

typedef struct s_obj_count
{
	unsigned int	obj;
	unsigned char	camera;
	unsigned char	ambient;
	unsigned char	light;
}	t_obj_count;

typedef struct s_hash_item
{
	char	*key;
	int		(*is_valid_obj)(char **);
	char	*error_msg;
}	t_hash_item;

typedef struct s_intersection_vars
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_intersection_vars;

void		free_arr(char **arr);
void		free_content(void *content);
void		free_scene(t_scene *scene);

int			is_valid_input(char *file, t_scene *scene);
int			read_file(char *file, t_scene *scene);
int			is_valid_extension(char *file);
void		show_error(char *msg);

int			is_valid_float(const char *str);
int			is_valid_coordinates(char *str);
int			is_valid_ratio(char *str);
int			is_valid_color(char *str);
int			is_valid_fov(char *str);
int			is_valid_normalized_vector(char *str);
int			is_valid_int(const char *str);
int			has_comment_or_spaces(char *line);

int			is_valid_ambient(char **arr);
int			is_valid_camera(char **arr);
int			is_valid_light(char **arr);
int			is_valid_sphere(char **arr);
int			is_valid_plane(char **arr);
int			is_valid_cylinder(char **arr);

int			has_enough_elements(t_obj_count count);

void		parse_elements(t_scene *scene);

void		parse_ambient(char **arr, t_scene *scene);
void		parse_camera(char **arr, t_scene *scene);
void		parse_light(char **arr, t_scene *scene);
void		parse_sphere(char **arr, t_scene *scene);
void		parse_plane(char **arr, t_scene *scene);
void		parse_cylinder(char **arr, t_scene *scene);

void		save_double(const char *token, double *dst);
void		save_color(const char *token, t_color *dst);
void		save_vec4(const char *token, t_vec4 *dst);

void		set_surface_sphere_quadric(t_surface_parameters *p);
void		set_surface_plane_quadric(t_surface_parameters *p);
void		set_surface_cylinder_quadric(t_surface_parameters *p);
void		set_surface_matrix(t_surface_parameters p, t_mat4 *m);
void		set_surface_type(t_surface_parameters *p);

t_surface	create_surface(t_surface_parameters p);
t_vec4		get_surface_normal(t_surface s, t_vec4 hit_point);

void		vec4_copy(t_vec4 *a, t_vec4 b);
double		vec4_mag(t_vec4 v);
t_vec4		vec4_normalize(t_vec4 v);
t_vec4		vec4_mat4_mul(t_vec4 v, t_mat4 m);
double		vec4_dot_prod(t_vec4 a, t_vec4 b);
t_vec4		vec4_cross_prod(t_vec4 a, t_vec4 b);
t_vec4		vec4_scale(t_vec4 v, double scalar);
t_vec4		vec4_add(t_vec4 a, t_vec4 b);
t_vec4		vec4_sub(t_vec4 a, t_vec4 b);
t_vec4		vec4_mul(t_vec4 a, t_vec4 b);
t_vec4		vec4_reflect(t_vec4 v, t_vec4 n);
int			vec4_to_int(t_vec4 c);
t_vec4		norm_color(t_color c);

t_mat4		mat4_rotation_from_to(t_vec4 from, t_vec4 to);
t_mat4		mat4_identity(void);
t_mat4		mat4_translation(t_vec4 t);
t_mat4		mat4_transpose(t_mat4 m);
t_mat4		mat4_mat4_mult(t_mat4 m1, t_mat4 m2);

double		intersection(t_ray *ray, t_surface *surf);

void		*init_env(t_env *env, int argc, char **argv);
void		*destroy_env(t_env *env);

void		*init_window(t_window *window,
				int width,
				int height,
				char *window_name);

void		*destroy_window(t_window *window);
int			close_window(t_env *env);

void		set_window_hooks(t_env *env);
int			key_hook(int keycode, void *param);

void		*init_img_buffer(t_window *window);
void		*destroy_img_buffer(t_window *window);

void		put_pixel_row(t_window *window,
				int y,
				unsigned int *colors);

void		render_loop(t_env *env);

double		calc_shadow(t_env *env,
				t_vec4 hit_p,
				t_surface *obj);

t_vec4		calc_light_components(
				t_env *env,
				t_surface *obj,
				t_light_componets_params *p);

int			calc_lighting(
				t_env *env,
				t_vec4 n,
				t_vec4 hit_p,
				t_surface *obj);

int			cast_ray(
				t_ray *ray,
				t_env *env,
				double *out_t);

#endif
