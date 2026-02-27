/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:03 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/27 18:02:22 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "scene_elements.h"

static int	validate_filename(char *filename)
{
	int	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 3)
		return (1);
	if (ft_strcmp(filename + len - 3, ".rt") != 0)
		return (1);
	return (0);
}

static int	check_limitations(t_parser *parser)
{
	int			obj_count;
	t_hittables	*ht;

	ht = parser->hittables;
	if (parser->amb_count > 1)
		return (print_error("error: too many ambients\n"));
	if (parser->cam_count > 1)
		return (print_error("error: too many cameras\n"));
	if (parser->lig_count > 1)
		return (print_error("error: too many lights\n"));
	obj_count = ht->plane_count
		+ ht->cylinder_count
		+ ht->sphere_count;
	if (obj_count > 300)
		return (print_error("error: too many objects\n"));
	return (0);
}

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_iswhitespace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	parse_line(char *line, t_parser *parser)
{
	if (is_empty_line(line))
		return (0);
	if (line_first(line, "A", 1))
		parser->amb_count++;
	else if (line_first(line, "C", 1))
		parser->cam_count++;
	else if (line_first(line, "L", 1))
		parser->lig_count++;
	else if (line_first(line, "pl", 2))
		parser->hittables->plane_count++;
	else if (line_first(line, "sp", 2))
		parser->hittables->sphere_count++;
	else if (line_first(line, "cy", 2))
		parser->hittables->cylinder_count++;
	else
		return (print_error("error: invalid file\n"));
	return (check_limitations(parser));
}

int	parse_file(char *filename, t_parser *parser)
{
	char	**file;
	int		error;
	int		i;

	if (validate_filename(filename))
		return (print_error("error\n"));
	file = file_to_array(filename);
	if (!file)
		return (print_error("error\n"));
	i = 0;
	error = 0;
	while (file[i] && !error)
		error = parse_line(file[i++], parser);
	free_arr(file);
	if (!error && (parser->amb_count != 1
			|| parser->cam_count != 1
			|| parser->lig_count != 1))
		return (print_error("error\n"));
	return (error);
}
