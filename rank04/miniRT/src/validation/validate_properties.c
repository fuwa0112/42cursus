/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:51:29 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/12 14:51:31 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "free_memory.h"
#include "libft.h"

#define EPSILON 1e-3

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
	char	**vectors;
	double	v[3];
	double	mag;
	int		i;

	if (!str || str[0] == '\0')
		return (0);
	vectors = ft_split_charset(str, ",");
	if (!vectors)
		return (0);
	i = -1;
	while (vectors[++i])
	{
		if (i >= 3 || !is_valid_float(vectors[i]))
			return (free_arr(vectors), 0);
		v[i] = ft_atof(vectors[i]);
		if (v[i] < -1.0 || v[i] > 1.0)
			return (free_arr(vectors), 0);
	}
	if (i != 3)
		return (free_arr(vectors), 0);
	mag = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	free_arr(vectors);
	return (fabs(mag - 1.0) <= EPSILON);
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
