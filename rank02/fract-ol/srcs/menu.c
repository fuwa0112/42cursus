/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:49:21 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 00:27:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	check_name_selection(char *argv, char *chaine)
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

static int	is_number(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_color(char *s)
{
	if (check_name_selection(s, "Origin"))
		return (0);
	if (check_name_selection(s, "Red"))
		return (1);
	if (check_name_selection(s, "Blue"))
		return (2);
	if (check_name_selection(s, "Green"))
		return (3);
	if (check_name_selection(s, "Gray"))
		return (4);
	return (-1);
}

static int	set_fractal_number(char *name)
{
	if (check_name_selection(name, "Julia"))
		return (0);
	if (check_name_selection(name, "Mandelbrot"))
		return (1);
	if (check_name_selection(name, "Burning_ship"))
		return (2);
	return (-1);
}

void	menu(int argc, char **argv, t_fractal **fractal)
{
	if (argc < 2)
		handle_error(*fractal);
	(*fractal)->number = set_fractal_number(argv[1]);
	if ((*fractal)->number == -1)
		handle_error(*fractal);
	if (argc >= 3)
	{
		if (parse_color(argv[2]) == -1)
			handle_error(*fractal);
		(*fractal)->color_config = parse_color(argv[2]);
	}
	if (argc >= 4)
	{
		if (!is_number(argv[3]))
			handle_error(*fractal);
		(*fractal)->c_re = ft_atoi(argv[3]);
	}
	if (argc >= 5)
	{
		if (!is_number(argv[4]))
			handle_error(*fractal);
		(*fractal)->c_i = ft_atoi(argv[4]);
	}
	if (argc > 5)
		handle_error(*fractal);
}
