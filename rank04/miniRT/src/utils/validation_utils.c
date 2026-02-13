/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:48:49 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 16:07:48 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	validate_rgb_range(t_color *rgb)
{
	int	error;

	error = 0;
	if (rgb->r < 0 || rgb->r > 255)
		error = 1;
	if (rgb->g < 0 || rgb->g > 255)
		error = 1;
	if (rgb->b < 0 || rgb->b > 255)
		error = 1;
	if (error)
		ft_putstr_fd("RGB values should be in range of [0, 255]!!\n", 1);
	return (error);
}

int	validate_rgb(char **rgb_l, t_color *rgb)
{
	int		ok;
	double	val;

	if (arg_count(rgb_l) == 3)
	{
		ok = ft_atof_vali(rgb_l[0], &val);
		if (!ok)
			return (ft_putstr_fd("Invalid RGB value!\n", 2), 1);
		rgb->r = val;
		ok = ft_atof_vali(rgb_l[1], &val);
		if (!ok)
			return (ft_putstr_fd("Invalid RGB value!\n", 2), 1);
		rgb->g = val;
		ok = ft_atof_vali(rgb_l[2], &val);
		if (!ok)
			return (ft_putstr_fd("Invalid RGB value!\n", 2), 1);
		rgb->b = val;
		return (validate_rgb_range(rgb));
	}
	return (ft_putstr_fd("Invalid RGB value!\n", 2), 1);
}
