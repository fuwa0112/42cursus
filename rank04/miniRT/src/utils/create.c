/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:00:24 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:02 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		create_amb(t_data *data, char **args);
int		create_cam(t_data *data, char **args);
int		create_light(t_data *data, char **args);
int		create_cylinder(t_data *data, char **args);
int		create_plane(t_data *data, char **args);
int		create_sphere(t_data *data, char **args);

void	display_sphere_obj_data(t_sphere *sp)
{
	printf("++++++++++++++++++++++++ Sphere +++++++++++++++++++++\n");
	printf("diameter: %.2f\n", sp->diameter);
	printf("x: %.2f, y: %.2f, z: %.2f\n", sp->position->x, sp->position->y,
		sp->position->z);
	printf("r : %f\n", sp->rgb->r);
	printf("g : %f\n", sp->rgb->g);
	printf("b : %f\n", sp->rgb->b);
}

int	create_acl(char **args, t_data *data)
{
	int	res;

	res = 0;
	if (ft_strncmp(args[0], "A", 1) == 0)
		res = create_amb(data, args);
	else if (ft_strncmp(args[0], "C", 1) == 0)
		res = create_cam(data, args);
	else if (ft_strncmp(args[0], "L", 1) == 0)
		res = create_light(data, args);
	return (res);
}

int	create_objects(char **args, t_data *data)
{
	int	res;

	res = create_acl(args, data);
	if (res == 1)
		return (1);
	if (ft_strncmp(args[0], "cy", 2) == 0)
		res = create_cylinder(data, args);
	else if (ft_strncmp(args[0], "pl", 2) == 0)
		res = create_plane(data, args);
	else if (ft_strncmp(args[0], "sp", 2) == 0)
		res = create_sphere(data, args);
	return (res);
}
