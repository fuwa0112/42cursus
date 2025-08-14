/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:25:06 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 00:27:54 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

typedef struct t_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		number;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	start_x;
	double	start_y;
	double	c_re;
	double	c_i;
	int		*adress;
	int		iteration;
	double	z_x;
	double	z_y;
	double	scale;
	int		color_config;
}			t_fractal;

int			print_key(int key, t_fractal **fractal);
int			on_destroy_event(t_fractal **fractal);
void		draw(t_fractal **fractal);
void		key_pressure(t_fractal **fractal);
void		draw_julia(t_fractal **fractal);
void		draw_mandelbrot(t_fractal **fractal);
int			ft_atoi(const char *nptr);
void		malloc_color(t_fractal **fractal);
void		instructions_display(void);
void		draw_burning_ship(t_fractal **fractal);
void		menu(int argc, char **argv, t_fractal **fractal);
void		init_fractal(t_fractal **fractal);
void		handle_error(t_fractal *fractal);

#endif