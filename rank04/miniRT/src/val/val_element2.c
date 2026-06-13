/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_element2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:29:00 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/14 02:51:45 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_valid_extension(char *file)
{
	int		len;
	char	*extension;

	if (!file)
	{
		show_error("Invalid file");
		return (0);
	}
	len = ft_strlen(file);
	extension = ft_strrchr(file, '.');
	if (!extension || len <= 3 || ft_strcmp(".rt", extension) != 0)
	{
		show_error("Invalid extension");
		return (0);
	}
	return (1);
}

int	is_valid_coordinates(char *str)
{
	int		i;
	char	**coordinates;

	if (str == NULL)
		return (0);
	coordinates = ft_split_charset(str, ",");
	if (coordinates == NULL)
		return (0);
	i = 0;
	while (coordinates[i])
	{
		if (!is_valid_float(coordinates[i]))
		{
			free_arr(coordinates);
			return (0);
		}
		i++;
	}
	free_arr(coordinates);
	if (i != 3)
		return (0);
	return (1);
}

int	is_valid_normalized_vector(char *str)
{
	char	**vstr;
	double	v[3];
	double	mag;
	int		i;

	if (!str || !*str)
		return (0);
	vstr = ft_split_charset(str, ",");
	if (!vstr)
		return (0);
	i = 0;
	while (i < 3 && vstr[i])
	{
		if (!is_valid_float(vstr[i]))
			return (free_arr(vstr), 0);
		v[i] = ft_atof(vstr[i]);
		i++;
	}
	if (i != 3 || vstr[i])
		return (free_arr(vstr), 0);
	free_arr(vstr);
	mag = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	return (fabs(mag - 1.0) <= EPSILONNORM);
}

int	is_valid_fov(char *str)
{
	int	fov;

	if (str == NULL || str[0] == '\0' || !is_valid_int(str))
		return (0);
	fov = ft_atoi(str);
	if (fov < 0 || fov > 180)
		return (0);
	return (1);
}

int	has_comment_or_spaces(char *line)
{
	if (line[0] == '#')
		return (1);
	while (ft_isspace(*line))
		line++;
	return (*line == '\0');
}
