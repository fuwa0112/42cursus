/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:29:01 by lshein            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:25 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	diameter_check(t_cylinder *cy, char *arg)
{
	int		ok;
	double	val;

	ok = ft_atof_vali(arg, &val);
	if (!ok)
	{
		free(cy);
		return (ft_putstr_fd("Invalid cylinder diameter!\n", 2), 1);
	}
	if (val <= 0)
	{
		free(cy);
		return (ft_putstr_fd("cylinder diameter should be greater than 0!\n",
				2), 1);
	}
	cy->diameter = val;
	return (0);
}

static int	height_check(t_cylinder *cy, char *arg)
{
	int		ok;
	double	val;

	ok = ft_atof_vali(arg, &val);
	if (!ok)
	{
		free(cy);
		return (ft_putstr_fd("Invalid cylinder height!\n", 2), 1);
	}
	if (val <= 0)
	{
		free(cy);
		return (ft_putstr_fd("cylinder height should be greater than 0!\n", 2),
			1);
	}
	cy->height = val;
	return (0);
}

static int	init_spec(t_cylinder *cy, char **args)
{
	char	**spec;
	int		ok;
	double	val;

	if (arg_count(args) == 7)
	{
		spec = ft_split2(args[6], "spec:");
		ok = ft_atof_vali(spec[0], &val);
		if (!ok)
		{
			free(cy->rgb);
			free(cy->position);
			free(cy->oriention);
			free(cy);
			free_2d(spec);
			return (ft_putstr_fd("Invalid cylinder spec!\n", 2), 1);
		}
		cy->spec = val;
		free_2d(spec);
	}
	return (0);
}

static int	init_ref(t_cylinder *cy, char **args)
{
	char	**ref;
	int		ok;
	double	val;

	if (arg_count(args) == 8)
	{
		ref = ft_split2(args[7], "ref:");
		ok = ft_atof_vali(ref[0], &val);
		if (!ok)
		{
			free(cy->rgb);
			free(cy->position);
			free(cy->oriention);
			free(cy);
			free_2d(ref);
			return (ft_putstr_fd("Invalid cylinder reflection!\n", 2), 1);
		}
		cy->reflection = val;
		free_2d(ref);
	}
	return (0);
}

t_cylinder	*init_cylinder(char **args)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (diameter_check(cy, args[3]))
		return (NULL);
	if (height_check(cy, args[4]))
		return (NULL);
	cy->rgb = malloc(sizeof(t_color));
	cy->position = malloc(sizeof(t_vec3));
	cy->oriention = malloc(sizeof(t_vec3));
	cy->radius = cy->diameter / 2;
	cy->spec = 0.0;
	cy->reflection = 0.0;
	if (init_spec(cy, args))
		return (NULL);
	if (init_ref(cy, args))
		return (NULL);
	return (cy);
}
