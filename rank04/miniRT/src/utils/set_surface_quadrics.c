/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_surface_quadrics.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:35:52 by hakama            #+#    #+#             */
/*   Updated: 2026/06/13 21:22:30 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_surface_sphere_quadric(t_surface_parameters *p)
{
	p->w = (t_vec4){.x = 1.0, .y = 1.0, .z = 1.0, .w = 0.0};
	p->l = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0};
	if (p->diameter == 0.0)
		p->diameter = -1.0;
	else
		p->diameter = -(p->diameter * p->diameter) / 4.0;
}

void	set_surface_plane_quadric(t_surface_parameters *p)
{
	p->w = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0};
	p->l = vec4_normalize(p->orientation);
	p->diameter = 0;
}

void	set_surface_cylinder_quadric(t_surface_parameters *p)
{
	p->w = (t_vec4){.x = 1.0, .y = 0.0, .z = 1.0, .w = 0.0};
	p->l = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0};
	if (p->diameter == 0.0)
		p->diameter = -1.0;
	else
		p->diameter = -(p->diameter * p->diameter) / 4.0;
}
