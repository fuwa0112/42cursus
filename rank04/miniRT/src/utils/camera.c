/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:17:45 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:07 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_camera(t_camera *c)
{
	if (!c)
		return ;
	if (c->position)
		free(c->position);
	if (c->oriention)
		free(c->oriention);
	free(c);
}

void	free_c_obj(t_camera *c, char **a, char **b)
{
	free_2d(a);
	free_2d(b);
	free_camera(c);
}

int	validate_fov(double fov)
{
	if (fov > 180.00 || fov < 0.00)
	{
		ft_putstr_fd("Error\nThe camera fov should be between 0, 180!!\n", 2);
		return (1);
	}
	return (0);
}

static int	fov_check(t_camera *c, char *arg)
{
	int		ok;
	double	val;

	ok = ft_atof_vali(arg, &val);
	if (!ok)
	{
		free(c);
		return (ft_putstr_fd("Invalid camera fov!\n", 2), 1);
	}
	c->fov = val;
	return (0);
}

t_camera	*create_camera_obj(char **args)
{
	t_camera	*c;
	char		**xyz_l;
	char		**xyz_v;

	if (arg_count(args) == 4)
	{
		c = malloc(sizeof(t_camera));
		if (fov_check(c, args[3]))
			return (NULL);
		c->position = malloc(sizeof(t_vec3));
		c->oriention = malloc(sizeof(t_vec3));
		xyz_l = ft_split2(args[1], ",");
		xyz_v = ft_split2(args[2], ",");
		if (validate_xyz(xyz_l, c->position, 0) == 1 || validate_xyz(xyz_v,
				c->oriention, 1) == 1 || validate_fov(c->fov) == 1)
			return (free_c_obj(c, xyz_l, xyz_v), NULL);
		free_2d(xyz_l);
		free_2d(xyz_v);
		return (c);
	}
	else
		ft_putstr_fd("Error\nInvalid camera format.\n", 2);
	return (NULL);
}
