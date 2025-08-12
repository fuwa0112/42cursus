/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:24:14 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/12 22:24:16 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_name_selection(char *argv, char *chaine)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (chaine[len])
		len++;
	while (argv[i])
		i++;
	if (i != len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (argv[i] != chaine[i])
			return (0);
		i++;
	}
	return (1);
}

void	menu(int argc, char **argv, t_fractal **fractal)
{
	if (argc == 1)
	{
		instructions_display();
		free(*fractal);
		exit(1);
	}
	if (check_name_selection(argv[1], "Julia"))
		(*fractal)->number = 0;
	if (check_name_selection(argv[1], "Mandelbrot"))
		(*fractal)->number = 1;
	if (check_name_selection(argv[1], "Burning_ship"))
		(*fractal)->number = 2;
	if (argc >= 3)
		(*fractal)->c_re = ft_atoi(argv[2]);
	if (argc == 4)
		(*fractal)->c_i = ft_atoi(argv[3]);
	if ((*fractal)->number == 99)
	{
		instructions_display();
		free(*fractal);
		exit(1);
	}
}

void	init_fractal(t_fractal **fractal)
{
	(*fractal)->number = 99;
	(*fractal)->c_re = -0.7;
	(*fractal)->c_i = 0.3;
	(*fractal)->zoom = 1.0;
	(*fractal)->start_x = 0;
	(*fractal)->start_y = 0;
	(*fractal)->iteration = 50;
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
		*((*fractal)->adress) = 0x123456;
		return ;
	}
	raw_address = (uintptr_t)(*fractal)->adress;
	*((*fractal)->adress) = raw_address ;
}
