/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:50:08 by hakama            #+#    #+#             */
/*   Updated: 2026/02/28 15:48:16 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	valid_fieldview(char *str, int *field_view)
{
	int	error;

	error = 0;
	*field_view = ft_atoi(str, &error);
	if (error == 1 || *field_view <= 0 || *field_view > 180)
		return (0);
	return (1);
}

void	parse_camera(char *line, t_data *data)
{
	char	**elements;
	double	cords[3];

	if (data->flags[CAMERA])
		free_data_andexit(data, line,
			"Error\nCamera provided more than one time\n");
	elements = split_whitespace(line);
	if (elements == NULL)
		free_data_andexit(data, line, "Error\nMalloc error\n");
	if (count_elements(elements) != 4 || !valid_cords(elements[1], cords,
			&data->camera.cord) || !valid_ncords(elements[2], cords,
			&data->camera.dir) || !valid_fieldview(elements[3],
			&data->camera.fov))
	{
		free_split(elements);
		free_data_andexit(data, line, "Error\nWrong params for camera\n");
	}
	return (data->flags[CAMERA] = 1, free_split(elements));
}
