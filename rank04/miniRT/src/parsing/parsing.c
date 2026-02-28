/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:50:27 by hakama            #+#    #+#             */
/*   Updated: 2026/02/28 18:41:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	file_check(char *f_name)
{
	int	i;
	int	fd;

	i = ft_strlen(f_name);
	if (i < 3)
		error("Error\nInvalid file: file must be .rt.\n");
	if (f_name[i - 3] != '.' || f_name[i - 2] != 'r' || f_name[i - 1] != 't')
		error("Error\nInvalid file: file must be .rt.\n");
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
	return (fd);
}

int	check_id(char *line)
{
	if (!line || !*line)
		return (0);
	if ((line[0] == 'A'
			|| line[0] == 'C'
			|| line[0] == 'L')
		&& is_space(line[1]))
		return (1);
	if ((line[0] == 's'
			&& line[1] == 'p'
			&& is_space(line[2]))
		|| (line[0] == 'p'
			&& line[1] == 'l'
			&& is_space(line[2]))
		|| (line[0] == 'c'
			&& line[1] == 'y'
			&& is_space(line[2])))
		return (1);
	return (0);
}

void	parse_line(char *line, t_data *data)
{
	if (check_id(line) == 0)
		free_data_andexit(data, line, "Error\nInvalid Id\n");
	if (line[0] == 'C')
		parse_camera(line, data);
	else if (line[0] == 's')
		parse_sphere(line, data);
	else if (line[0] == 'p')
		parse_plane(line, data);
	else if (line[0] == 'c')
		parse_cylinder(line, data);
	else if (line[0] == 'L')
		parse_light(line, data);
	else if (line[0] == 'A')
		parse_ambient_light(line, data);
}

void	change_objects_array(t_data *data)
{
	t_objects	*current;
	int			i;

	data->objects = malloc(sizeof(t_objects *) * data->num_objects);
	if (data->objects == NULL)
		free_data_andexit(data, NULL, "Error\nMalloc error\n");
	i = 0;
	current = data->parse_obj;
	while (i < data->num_objects)
	{
		data->objects[i] = current;
		i++;
		current = current->next;
	}
}

void	check_scene(t_data *data)
{
	char	*line;
	char	*tmp;

	line = get_next_line(data->fd);
	while (line != NULL)
	{
		tmp = line;
		line = ft_strtrim(line);
		free(tmp);
		if (line == NULL)
			free_data_andexit(data, NULL, "Error\nMalloc error\n");
		if (ft_strlen(line) > 0)
			parse_line(line, data);
		free(line);
		line = get_next_line(data->fd);
	}
	if (data->flags[CAMERA] && data->flags[LIGHT] && data->flags[A_LIGHT]
		&& data->parse_obj)
		change_objects_array(data);
	else
		free_data_andexit(data, NULL, "Error\nMissing params.\n");
}
