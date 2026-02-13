/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:49:17 by hthant            #+#    #+#             */
/*   Updated: 2026/02/12 14:01:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

char	**read_lines(const char *path, int line_count)
{
	int		fd;
	int		i;
	char	**lines;
	char	*line;

	i = 0;
	lines = malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line && i < line_count)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

int	parse_scene(char *argv, t_data *data, int line_count)
{
	int		i;
	char	**lines;
	char	**args;

	i = 0;
	lines = read_lines(argv, line_count);
	if (!lines)
		return (1);
	count_type(lines, data);
	count_objects(lines, data);
	if (init_objects(data))
		return (free_lines(lines), 1);
	while (lines[i])
	{
		if (lines[i][0] != '\n')
		{
			args = ft_split2(lines[i], " \t");
			if (create_objects(args, data))
				return (free_2d(args), free_lines(lines), 1);
			free_2d(args);
		}
		i++;
	}
	return (free_lines(lines), 0);
}

int	parse_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nToo many params or not enough param!\n", 2);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (!argv[1] || !argv[1][0])
	{
		ft_putstr_fd("Error\nThe param shouldn't be empty!\n", 2);
		return (1);
	}
	if (len < 4 || ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
	{
		ft_putstr_fd("Error\nInvalid file type!!\n", 2);
		return (1);
	}
	return (0);
}
