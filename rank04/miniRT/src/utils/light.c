/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:55:42 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:38 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_light(t_light *l)
{
	free(l->rgb);
	free(l->position);
	free(l);
}

void	free_l_obj(t_light *l, char **a, char **b)
{
	free_2d(a);
	free_2d(b);
	free_light(l);
}

void	free_light_arr(t_light **l)
{
	int	i;

	if (!l)
		return ;
	i = 0;
	while (l[i])
	{
		free_light(l[i]);
		i++;
	}
	free(l);
}

t_light	*init_light(char **args)
{
	t_light	*l;
	int		ok;
	double	val;

	l = malloc(sizeof(t_light));
	ok = ft_atof_vali(args[2], &val);
	if (!ok)
	{
		free(l);
		return (ft_putstr_fd("Invalid light brightness!\n", 2), NULL);
	}
	l->brightness = val;
	l->rgb = malloc(sizeof(t_color));
	l->position = malloc(sizeof(t_vec3));
	return (l);
}

t_light	*create_light_obj(char **args)
{
	t_light	*l;
	char	**rgb_l;
	char	**xyz_l;

	if (arg_count(args) == 4)
	{
		l = init_light(args);
		if (!l)
			return (NULL);
		rgb_l = ft_split2(args[3], ",");
		xyz_l = ft_split2(args[1], ",");
		if (validate_ratio(0.0, 1.0, l->brightness, "Light brightness") == 1
			|| validate_rgb(rgb_l, l->rgb) == 1 || validate_xyz(xyz_l,
				l->position, 0) == 1)
		{
			free_l_obj(l, rgb_l, xyz_l);
			return (NULL);
		}
		free_2d(rgb_l);
		free_2d(xyz_l);
		return (l);
	}
	else
		ft_putstr_fd("Error\nInvalid light format.\n", 2);
	return (NULL);
}
