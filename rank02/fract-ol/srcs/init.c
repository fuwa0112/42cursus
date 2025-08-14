/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:24:14 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 00:55:04 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_error(t_fractal *fractal)
{
	instructions_display();
	free(fractal);
	exit(1);
}

void	init_fractal(t_fractal **fractal)
{
	(*fractal)->number = -1;
	(*fractal)->c_re = -0.7;
	(*fractal)->c_i = 0.3;
	(*fractal)->zoom = 1.0;
	(*fractal)->start_x = 0;
	(*fractal)->start_y = 0;
	(*fractal)->iteration = 50;
	(*fractal)->color_config = 0;
	(*fractal)->mlx = NULL;
	(*fractal)->win = NULL;
	(*fractal)->img = NULL;
	(*fractal)->addr = NULL;
	(*fractal)->adress = NULL;
}

void	malloc_color(t_fractal **fractal)
{
	uintptr_t	raw_address;

	(*fractal)->adress = malloc(sizeof(int));
	if (!(*fractal)->adress)
	{
		free((*fractal)->mlx);
		free(*fractal);
		exit(1);
	}
	if ((*fractal)->color_config == 0)
	{
		raw_address = (uintptr_t)(*fractal)->adress;
		*(*fractal)->adress = raw_address;
	}
	else if ((*fractal)->color_config == 1)
		*(*fractal)->adress = 0xFF1111;
	else if ((*fractal)->color_config == 2)
		*(*fractal)->adress = 0x1111FF;
	else if ((*fractal)->color_config == 3)
		*(*fractal)->adress = 0x11FF11;
	else if ((*fractal)->color_config == 4)
		*(*fractal)->adress = 0x111111;
}
