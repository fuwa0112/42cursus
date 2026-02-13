/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:51:25 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:51:26 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec(double x, double y, double z);
t_vec3		vec_add(t_vec3 a, t_vec3 b);
t_vec3		vec_sub(t_vec3 a, t_vec3 b);
double		vec_length(t_vec3 v);
double		vec_dot(t_vec3 a, t_vec3 b);
t_vec3		vec_normalize(t_vec3 v);
t_vec3		vec_cross(t_vec3 a, t_vec3 b);
t_vec3		vec_mul(t_vec3 v, double scalar);
t_vec3		vec_div(t_vec3 v, double s);

#endif
