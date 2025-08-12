/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:23:13 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/12 22:34:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(1);
	init_fractal(&fractal);
	menu(argc, argv, &fractal);
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		free(fractal);
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	malloc_color(&fractal);
	draw(&fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	key_pressure(&fractal);
}
