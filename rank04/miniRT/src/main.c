/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:40:06 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:59 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		line_count;

	if (parse_args(argc, argv) == 1)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_bzero(data, sizeof(t_data));
	if (init_object_counts(data) == 1)
		return (free_data(data), 1);
	line_count = count_lines(argv[1]);
	if (line_count <= 0)
		return (1);
	if (parse_scene(argv[1], data, line_count) == 1)
		return (free_data(data), 1);
	if (init_mlx(data) == 1)
		return (free_data(data), 1);
	if (init_viewport(data) == 1)
		return (free_data(data), 1);
	render_scene(data);
	free_mlx(data);
	free_data(data);
	return (0);
}
