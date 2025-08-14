/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:24:49 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 00:52:57 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	on_destroy_event(t_fractal **fractal)
{
	mlx_destroy_image((*fractal)->mlx, (*fractal)->img);
	mlx_destroy_window((*fractal)->mlx, (*fractal)->win);
	mlx_loop_end((*fractal)->mlx);
	mlx_destroy_display((*fractal)->mlx);
	free((*fractal)->adress);
	free((*fractal)->mlx);
	free(*fractal);
	exit(1);
}

int	key_action(int key, t_fractal **fractal)
{
	if (key == 65363)
		(*fractal)->start_x += 0.1 * (*fractal)->zoom;
	if (key == 65361)
		(*fractal)->start_x -= 0.1 * (*fractal)->zoom;
	if (key == 65364)
		(*fractal)->start_y += 0.1 * (*fractal)->zoom;
	if (key == 65362)
		(*fractal)->start_y -= 0.1 * (*fractal)->zoom;
	if (key == 65307)
		on_destroy_event(fractal);
	if (key == 'q')
		(*fractal)->c_i += 0.01;
	if (key == 'w')
		(*fractal)->c_i -= 0.01;
	if (key == 'a')
		(*fractal)->c_re += 0.01;
	if (key == 's')
		(*fractal)->c_re -= 0.01;
	if (key == 'i')
		(*fractal)->iteration += 50;
	draw(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractal	*fractal;

	(void)x;
	(void)y;
	fractal = (t_fractal *)param;
	if (button == 5)
		fractal->zoom *= 1.1;
	else if (button == 4)
		fractal->zoom *= 0.9;
	draw(&fractal);
	return (0);
}

void	draw(t_fractal **fractal)
{
	if ((*fractal)->number == 0)
		draw_julia(fractal);
	if ((*fractal)->number == 1)
		draw_mandelbrot(fractal);
	if ((*fractal)->number == 2)
		draw_burning_ship(fractal);
}

void	key_pressure(t_fractal **fractal)
{
	mlx_mouse_hook((*fractal)->win, mouse_hook, *fractal);
	mlx_key_hook((*fractal)->win, key_action, fractal);
	mlx_hook((*fractal)->win, 17, 0, on_destroy_event, fractal);
	mlx_loop((*fractal)->mlx);
}
