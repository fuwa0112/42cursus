/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:01:38 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:49:53 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	validate_rgb_range(t_color *rgb);
int	validate_rgb(char **rgb_l, t_color *rgb);

int	validate_ratio(double least, double most, double input, char *element)
{
	if (input < least || input > most)
	{
		ft_putstr_fd(element, 2);
		ft_putstr_fd(" ratio should be in range of [", 2);
		ft_putnbr_fd(least, 2);
		ft_putstr_fd(".0, ", 2);
		ft_putnbr_fd(most, 2);
		ft_putstr_fd(".0]!!\n", 2);
		return (1);
	}
	return (0);
}

int	print_invalid_vec(double val, char axis)
{
	if (val < -1 || val > 1)
	{
		if (axis == 'x')
			ft_putstr_fd("Invalid x vec!!\n", 2);
		else if (axis == 'y')
			ft_putstr_fd("Invalid y vec!!\n", 2);
		else if (axis == 'z')
			ft_putstr_fd("Invalid z vec!!\n", 2);
		return (1);
	}
	return (0);
}

int	validate_vec(char **xyz_l, t_vec3 *vec)
{
	double	val;
	int		ok;

	ok = ft_atof_vali(xyz_l[0], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid vector value!\n", 2), 1);
	vec->x = val;
	ok = ft_atof_vali(xyz_l[1], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid vector value!\n", 2), 1);
	vec->y = val;
	ok = ft_atof_vali(xyz_l[2], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid vector value!\n", 2), 1);
	vec->z = val;
	if (print_invalid_vec(vec->x, 'x') || print_invalid_vec(vec->y, 'y')
		|| print_invalid_vec(vec->z, 'z'))
		return (1);
	return (0);
}

int	validate_coordinates(char **xyz_l, t_vec3 *xyz)
{
	double	val;
	int		ok;

	ok = ft_atof_vali(xyz_l[0], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid coordinate value!\n", 2), 1);
	xyz->x = val;
	ok = ft_atof_vali(xyz_l[1], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid coordinate value!\n", 2), 1);
	xyz->y = val;
	ok = ft_atof_vali(xyz_l[2], &val);
	if (!ok)
		return (ft_putstr_fd("Invalid coordinate value!\n", 2), 1);
	xyz->z = val;
	return (0);
}

int	validate_xyz(char **xyz_l, t_vec3 *xyz, int vec)
{
	if (arg_count(xyz_l) != 3)
	{
		if (vec == 0)
			ft_putstr_fd("Incomplete coordinate!!\n", 2);
		else
			ft_putstr_fd("Incomplete vector!!\n", 2);
		return (1);
	}
	if (vec == 1)
		return (validate_vec(xyz_l, xyz));
	return (validate_coordinates(xyz_l, xyz));
}
