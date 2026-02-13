/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:51:08 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 14:30:45 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include <X11/keysym.h>
// #include <X11/X.h>
// #include <X11/Xlib.h>
# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"
# include "mlx_utils.h"
# include "object.h"
# include "ray.h"
# include "vector.h"

# define W_W 1080
# define W_H 607
# define SAMPLES_PER_PIXEL 10
# define DEPTH 3
# define PI 3.1415926535
# define EPSILON 1e-4
# define SPECULAR_POWER 100

typedef struct s_data
{
	void			*mlx;
	void			*window;
	t_ambient		*ambient;
	t_camera		*camera;
	t_light			**light;
	t_sphere		**sphere;
	t_plane			**plane;
	t_cylinder		**cylinder;
	t_object_count	*objects;
	t_image			*img;
	t_image			*p_img;
	t_viewport		*viewport;
	t_hit			*hit_record;
}					t_data;

//	init.c
int					init_mlx(t_data *data);
int					init_object_counts(t_data *data);
int					init_image(int width, void *mlx, t_image *img);
int					init_objects(t_data *data);
int					init_viewport(t_data *data);
void				init_viewport_pixel(t_data *data, t_vec3 world_up);

//	parse.c
int					parse_args(int argc, char **argv);
int					parse_scene(char *argv, t_data *data, int line_count);

//	count.c
void				count_objects(char **lines, t_data *data);
void				count_type(char **lines, t_data *data);
int					count_lines(const char *path);

//	free.c
void				free_2d(char **str);
void				free_mlx(t_data *data);
void				free_data(t_data *data);
void				free_lines(char **lines);

// utils.c
int					ft_atof_vali(const char *str, double *result);
int					arg_count(char **arg);

// validation.c
int					validate_rgb(char **rgb_l, t_color *rgb);
int					validate_vec(char **xyz_l, t_vec3 *vec);
int					validate_ratio(double least, double most, double input,
						char *element);
int					validate_xyz(char **xyz_l, t_vec3 *xyz, int vec);

// render.c
void				render_scene(t_data *data);

// intersection
int					intersect_sphere(t_ray ray, t_sphere *sphere, t_hit *hit,
						double max_t);
int					intersect_plane(t_ray *ray, t_plane *plane, t_hit *hit);
int					intersect_cylinder(t_ray *ray, t_cylinder *cylinder,
						t_hit *hit);
int					find_nearest_sphere(t_ray ray, t_data *data);
int					find_nearest_plane(t_ray ray, t_data *data);
int					find_nearest_cylinder(t_ray ray, t_data *data);

// cy intersect utils
void				check_caps(t_ray *ray, t_cylinder *cylinder, t_t *hit_t);
void				is_within_height(t_t *t_values, t_cylinder *cylinder);
double				discriminant_cy(t_ray *ray, t_cylinder *cylinder, double *a,
						double *b);
void				cap_intersection(t_ray ray, t_cylinder *cylinder,
						t_vec3 cap_center, t_t *hit_t);

// render_utils.c
void				put_pixel(t_data *data, int color, int is_image, int xy[]);
t_vec3				vec_reflect(t_vec3 v, t_vec3 n);
t_color				color_add(t_color a, t_color b);
t_color				color_blend(t_color base, t_color overlay, double alpha);

// color_utils.c
int					color_to_int(t_color color);
t_color				int_to_color(int color);
t_vec3				color_to_vec3(t_color color);
t_color				vec3_to_color(t_vec3 vec);
t_vec3				int_to_vec3(int color);
int					vec3_to_int(t_vec3 vec);

// render_mlx_utils.c
void				draw_bar_only(t_data *data, int y);
char				*get_progress_string(int y);
void				display_rendering_text(t_data *data, char *progress);

// mlx_window_utils.c
int					close_window(t_data *data);
int					handle_keypress(int keysym, t_data *data);
int					create_objects(char **args, t_data *data);

// render_computations.c
void				compute_light_direction(t_vec3 *light_dir,
						double *light_dist, t_vec3 light_pos, t_vec3 hit_point);
t_color				compute_diffuse_contribution(t_hit hit, t_vec3 light_dir,
						t_color base_color, t_light *light);
t_color				compute_specular_contribution(t_hit hit, t_vec3 light_dir,
						t_ray ray, t_light *light);
t_color				do_reflection(int depth, t_ray ray, t_data *data,
						t_color final);
t_color				get_lighting(t_data *data, t_hit hit, t_color base_color,
						t_ray ray);

// shadow_utils.c
int					check_all_shadows(t_data *data, double light_dist,
						t_vec3 light_dir);

// ray.c
t_ray				get_ray(t_data *data, int x, int y);
double				random_double(void);
t_color				trace_ray(t_ray ray, t_data *data, int depth);

// display_utils.c
void				display_cylinder_obj_data(t_cylinder *cy);
void				display_plane_obj_data(t_plane *pl);
void				display_light_obj_data(t_light *l);
void				display_camera_obj_data(t_camera *c);
void				display_ambient_obj_data(t_ambient *ambient);

// objects
void				free_ambient(t_ambient *ambient);
void				free_camera(t_camera *camera);
void				free_light(t_light *light);
void				free_sphere(t_sphere *sphere);
void				free_plane(t_plane *plane);
void				free_cylinder(t_cylinder *cylinder);

void				free_light_arr(t_light **light);
void				free_sphere_arr(t_sphere **sphere, t_data *data);
void				free_plane_arr(t_plane **plane);
void				free_cylinder_arr(t_cylinder **cylinder);

int					check_light_positions(t_object_count *scene, t_light *light,
						t_data *data);
#endif
