/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:50:14 by hakama            #+#    #+#             */
/*   Updated: 2026/02/28 15:24:54 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	valid_brightness(char *str, double *ratio)
{
	int	error;

	error = 0;
	*ratio = ft_atof(str, &error);
	if (error == 1)
		return (0);
	if (*ratio < 0.0 || *ratio > 1.0)
		return (0);
	return (1);
}

void	parse_light(char *line, t_data *data)
{
	char	**elements;
	int		i;
	double	cords[3];

	if (data->flags[LIGHT])
		free_data_andexit(data, line,
			"Error\nLight provided more than one time\n");
	elements = split_whitespace(line);
	if (elements == NULL)
		free_data_andexit(data, line, "Error\nMalloc error\n");
	i = 0;
	while (elements[i])
		i++;
	if (i != 4 || !valid_cords(elements[1], cords, &data->light.cord)
		|| !valid_brightness(elements[2], &data->light.brightness)
		|| !valid_rgb(elements[3], &data->light.rgb))
	{
		free_split(elements);
		free_data_andexit(data, line, "Error\nWrong params for Light\n");
	}
	data->flags[LIGHT] = 1;
	free_split(elements);
}

void	parse_ambient_light(char *line, t_data *data)
{
	char	**elements;
	int		i;

	if (data->flags[A_LIGHT])
		free_data_andexit(data, line,
			"Error\nLight provided more than one time\n");
	elements = split_whitespace(line);
	if (elements == NULL)
		free_data_andexit(data, line, "Error\nMalloc error\n");
	i = 0;
	while (elements[i])
		i++;
	if (i != 3 || !valid_brightness(elements[1], &data->ambient_light.ratio)
		|| !valid_rgb(elements[2], &data->ambient_light.rgb))
	{
		free_split(elements);
		free_data_andexit(data, line,
			"Error\nWrong params for Ambient light\n");
	}
	data->flags[A_LIGHT] = 1;
	free_split(elements);
}
