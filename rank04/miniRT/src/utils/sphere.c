/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:20:10 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:55 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_sphere	*init_sphere(char **args);

void	free_sphere(t_sphere *sp)
{
	free(sp->rgb);
	free(sp->position);
	free(sp);
}

void	free_sp_obj(char **rgb_l, char **xyz_l, t_sphere *sp)
{
	free_2d(rgb_l);
	free_2d(xyz_l);
	free_sphere(sp);
}

void	free_sphere_arr(t_sphere **sp, t_data *data)
{
	int	i;

	if (!sp)
		return ;
	i = 0;
	while (i < data->objects->sphere_count)
	{
		if (sp[i])
			free_sphere(sp[i]);
		i++;
	}
	free(sp);
}

t_sphere	*create_sphere_obj(char **args)
{
	t_sphere	*sp;
	char		**rgb_l;
	char		**xyz_l;

	if (arg_count(args) == 4 || arg_count(args) == 5 || arg_count(args) == 6)
	{
		sp = init_sphere(args);
		if (!sp)
			return (NULL);
		rgb_l = ft_split2(args[3], ",");
		xyz_l = ft_split2(args[1], ",");
		if (validate_rgb(rgb_l, sp->rgb) == 1 || validate_xyz(xyz_l,
				sp->position, 0) == 1)
		{
			free_sp_obj(rgb_l, xyz_l, sp);
			return (NULL);
		}
		free_2d(rgb_l);
		free_2d(xyz_l);
		return (sp);
	}
	else
		ft_putstr_fd("Error\nInvalid sphere format.\n", 2);
	return (NULL);
}
