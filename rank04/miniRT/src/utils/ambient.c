/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:24:07 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:02:45 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_ambient(t_ambient *ambient)
{
	if (ambient->rgb)
		free(ambient->rgb);
	if (ambient)
		free(ambient);
}

void	free_a_obj(t_ambient *am, char **rgb_l)
{
	free_2d(rgb_l);
	free_ambient(am);
}

int	do_validation(double ratio, t_color *rgb, char **rgb_l, t_ambient *ambient)
{
	if (validate_ratio(0.0, 1.0, ratio, "Ambient lighting") == 1
		|| validate_rgb(rgb_l, rgb) == 1)
	{
		free(rgb);
		free_a_obj(ambient, rgb_l);
		return (0);
	}
	return (1);
}

static t_ambient	*free_notok(t_color *rgb, t_ambient *ambient, char **rgb_l)
{
	free(rgb);
	free(ambient);
	free_2d(rgb_l);
	return (ft_putstr_fd("Invalid ambient ratio!\n", 2), NULL);
}

t_ambient	*create_ambient_obj(char **args)
{
	double		ratio;
	char		**rgb_l;
	t_color		*rgb;
	t_ambient	*ambient;
	int			ok;

	if (arg_count(args) == 3)
	{
		ambient = malloc(sizeof(t_ambient));
		ambient->rgb = NULL;
		rgb = malloc(sizeof(t_color));
		rgb_l = ft_split2(args[2], ",");
		ok = ft_atof_vali(args[1], &ratio);
		if (!ok)
			return (free_notok(rgb, ambient, rgb_l));
		if (do_validation(ratio, rgb, rgb_l, ambient) != 1)
			return (NULL);
		ambient->lighting_ratio = ratio;
		ambient->rgb = rgb;
		free_2d(rgb_l);
		return (ambient);
	}
	else
		ft_putstr_fd("Error\nToo many or not enough arguments ambient.\n", 2);
	return (NULL);
}
