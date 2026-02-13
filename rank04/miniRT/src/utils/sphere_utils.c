/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:00:17 by lshein            #+#    #+#             */
/*   Updated: 2026/02/12 14:03:51 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	init_spec(t_sphere *sp, char **args)
{
	char	**spec;
	int		ok;
	double	val;

	if (arg_count(args) == 5)
	{
		spec = ft_split2(args[4], "spec:");
		ok = ft_atof_vali(spec[0], &val);
		if (!ok)
		{
			free(sp->rgb);
			free(sp->position);
			free(sp);
			free_2d(spec);
			return (ft_putstr_fd("Invalid sphere spec!\n", 2), 1);
		}
		sp->spec = val;
		free_2d(spec);
	}
	return (0);
}

static int	init_ref(t_sphere *sp, char **args)
{
	char	**ref;
	int		ok;
	double	val;

	if (arg_count(args) == 6)
	{
		ref = ft_split2(args[5], "ref:");
		ok = ft_atof_vali(ref[0], &val);
		if (!ok)
		{
			free(sp->rgb);
			free(sp->position);
			free(sp);
			free_2d(ref);
			return (ft_putstr_fd("Invalid sphere reflection!\n", 2), 1);
		}
		sp->reflection = val;
		free_2d(ref);
	}
	return (0);
}

t_sphere	*init_sphere(char **args)
{
	t_sphere	*sp;
	int			ok;
	double		val;

	sp = malloc(sizeof(t_sphere));
	ok = ft_atof_vali(args[2], &val);
	if (!ok || val <= 0)
	{
		free(sp);
		return (ft_putstr_fd("Invalid sphere diameter!\n", 2), NULL);
	}
	sp->rgb = malloc(sizeof(t_color));
	sp->diameter = val;
	sp->position = malloc(sizeof(t_vec3));
	sp->radius = sp->diameter / 2;
	sp->reflection = 0.0;
	sp->spec = 0.0;
	if (init_spec(sp, args))
		return (NULL);
	if (init_ref(sp, args))
		return (NULL);
	return (sp);
}
