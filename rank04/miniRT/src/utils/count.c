/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:40 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:02:10 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	count_type(char **lines, t_data *data)
{
	int		i;
	char	**args;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] != '\n')
		{
			args = ft_split2(lines[i], " 	");
			if (!args)
				return ;
			if (!ft_strncmp(args[0], "A", 2))
				data->objects->ambient_count++;
			else if (!ft_strncmp(args[0], "C", 2))
				data->objects->camera_count++;
			else if (!ft_strncmp(args[0], "L", 2))
				data->objects->light_count++;
			free_2d(args);
		}
		i++;
	}
}

void	count_objects(char **lines, t_data *data)
{
	int		i;
	char	**args;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] != '\n')
		{
			args = ft_split2(lines[i], " 	");
			if (!args)
				return ;
			if (!ft_strncmp(args[0], "cy", 3))
				data->objects->cylinder_count++;
			else if (!ft_strncmp(args[0], "pl", 3))
				data->objects->plane_count++;
			else if (!ft_strncmp(args[0], "sp", 3))
				data->objects->sphere_count++;
			free_2d(args);
		}
		i++;
	}
}

int	count_lines(const char *path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
