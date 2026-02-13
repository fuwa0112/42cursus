/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:41:20 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:28 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_cylinder	*init_cylinder(char **args);

void	free_cylinder(t_cylinder *cy)
{
	free(cy->rgb);
	free(cy->position);
	free(cy->oriention);
	free(cy);
}

void	free_cy_obj(char **xyz_l, char **xyz_v, char **rgb_l, t_cylinder *cy)
{
	free_2d(xyz_l);
	free_2d(xyz_v);
	free_2d(rgb_l);
	free_cylinder(cy);
}

void	free_cylinder_arr(t_cylinder **cy)
{
	int	i;

	if (!cy)
		return ;
	i = 0;
	while (cy[i])
	{
		free_cylinder(cy[i]);
		i++;
	}
	free(cy);
}

t_cylinder	*create_cylinder_obj(char **args)
{
	t_cylinder	*cy;
	char		**xyz_l;
	char		**xyz_v;
	char		**rgb_l;

	if (arg_count(args) == 7 || arg_count(args) == 8 || arg_count(args) == 6)
	{
		cy = init_cylinder(args);
		if (!cy)
			return (NULL);
		xyz_l = ft_split2(args[1], ",");
		xyz_v = ft_split2(args[2], ",");
		rgb_l = ft_split2(args[5], ",");
		if (validate_xyz(xyz_l, cy->position, 0) == 1 || validate_xyz(xyz_v,
				cy->oriention, 1) == 1 || validate_rgb(rgb_l, cy->rgb) == 1)
			return (free_cy_obj(xyz_l, xyz_v, rgb_l, cy), NULL);
		free_2d(xyz_l);
		free_2d(xyz_v);
		free_2d(rgb_l);
		return (cy);
	}
	else
		ft_putstr_fd("Error\nInvalid cylinder format.\n", 2);
	return (NULL);
}
