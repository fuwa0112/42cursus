/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:45:21 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:12 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	display_ambient_obj_data(t_ambient *ambient)
{
	printf("++++++++++++++++++++++++ Ambient +++++++++++++++++++++\n");
	printf("ratio : %.2f\n", ambient->lighting_ratio);
	printf("r : %f\n", ambient->rgb->r);
	printf("g : %f\n", ambient->rgb->g);
	printf("b : %f\n", ambient->rgb->b);
}

void	display_camera_obj_data(t_camera *c)
{
	printf("++++++++++++++++++++++++ Camera +++++++++++++++++++++\n");
	printf("x: %.2f, y: %.2f, z: %.2f\n", c->position->x, c->position->y,
		c->position->z);
	printf("x: %.2f, y: %.2f, z: %.2f\n", c->oriention->x, c->oriention->y,
		c->oriention->z);
	printf("angle: %.2f\n", c->fov);
}

void	display_light_obj_data(t_light *l)
{
	printf("++++++++++++++++++++++++ Light +++++++++++++++++++++\n");
	printf("x: %.2f, y: %.2f, z: %.2f\n", l->position->x, l->position->y,
		l->position->z);
	printf("ratio: %.2f\n", l->brightness);
	printf("r : %f\n", l->rgb->r);
	printf("g : %f\n", l->rgb->g);
	printf("b : %f\n", l->rgb->b);
}

void	display_cylinder_obj_data(t_cylinder *cy)
{
	printf("++++++++++++++++++++++++ Cylinder +++++++++++++++++++++\n");
	printf("diameter: %.2f\n", cy->diameter);
	printf("height: %.2f\n", cy->height);
	printf("x: %.2f, y: %.2f, z: %.2f\n", cy->position->x, cy->position->y,
		cy->position->z);
	printf("x: %.2f, y: %.2f, z: %.2f\n", cy->oriention->x, cy->oriention->y,
		cy->oriention->z);
	printf("r : %f\n", cy->rgb->r);
	printf("g : %f\n", cy->rgb->g);
	printf("b : %f\n", cy->rgb->b);
}

void	display_plane_obj_data(t_plane *pl)
{
	printf("++++++++++++++++++++++++ Plane +++++++++++++++++++++\n");
	printf("x: %.2f, y: %.2f, z: %.2f\n", pl->position->x, pl->position->y,
		pl->position->z);
	printf("x: %.2f, y: %.2f, z: %.2f\n", pl->oriention->x, pl->oriention->y,
		pl->oriention->z);
	printf("r : %f\n", pl->rgb->r);
	printf("g : %f\n", pl->rgb->g);
	printf("b : %f\n", pl->rgb->b);
}
