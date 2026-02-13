/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:20:13 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_plane(t_plane *pl)
{
	free(pl->rgb);
	free(pl->position);
	free(pl->oriention);
	free(pl);
}

void	free_pl_obj(char **xyz_l, char **xyz_v, char **rgb_l, t_plane *pl)
{
	free_2d(xyz_l);
	free_2d(xyz_v);
	free_2d(rgb_l);
	free_plane(pl);
}

void	free_plane_arr(t_plane **pl)
{
	int	i;

	if (!pl)
		return ;
	i = 0;
	while (pl[i])
	{
		free_plane(pl[i]);
		i++;
	}
	free(pl);
}

t_plane	*init_plane(char **args)
{
	t_plane	*pl;
	char	**spec;
	int		ok;
	double	val;

	pl = malloc(sizeof(t_plane));
	pl->rgb = malloc(sizeof(t_color));
	pl->position = malloc(sizeof(t_vec3));
	pl->oriention = malloc(sizeof(t_vec3));
	pl->spec = 0.0;
	if (arg_count(args) == 5)
	{
		spec = ft_split2(args[4], "spec:");
		ok = ft_atof_vali(spec[0], &val);
		if (!ok)
		{
			free_plane(pl);
			free_2d(spec);
			return (ft_putstr_fd("Invalid plane spec!\n", 2), NULL);
		}
		pl->spec = val;
		free_2d(spec);
	}
	return (pl);
}

t_plane	*create_plane_obj(char **args)
{
	t_plane	*pl;
	char	**xyz_l;
	char	**xyz_v;
	char	**rgb_l;

	if (arg_count(args) == 5 || arg_count(args) == 4)
	{
		pl = init_plane(args);
		if (!pl)
			return (NULL);
		xyz_l = ft_split2(args[1], ",");
		xyz_v = ft_split2(args[2], ",");
		rgb_l = ft_split2(args[3], ",");
		if (validate_xyz(xyz_l, pl->position, 0) == 1 || validate_xyz(xyz_v,
				pl->oriention, 1) == 1 || validate_rgb(rgb_l, pl->rgb) == 1)
			return (free_pl_obj(xyz_l, xyz_v, rgb_l, pl), NULL);
		free_2d(xyz_l);
		free_2d(xyz_v);
		free_2d(rgb_l);
		return (pl);
	}
	else
		ft_putstr_fd("Error\nInvalid plane format.\n.\n", 2);
	return (NULL);
}
