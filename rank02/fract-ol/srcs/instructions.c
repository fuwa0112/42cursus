/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:24:28 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/12 22:40:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	instructions_display(void)
{
	ft_printf(
		"------------------- Available fractals -------------------\n\n"
		"  - Julia\n"
		"  - Mandelbrot\n"
		"  - Burning_ship\n\n"
		);
	ft_printf(
		"Run the program like this in the terminal:\n\n"
		"  ./fract-ol <fractal name> [real constant] [imaginary constant]\n\n"
		"(The last two parameters are optional for Julia sets.)\n\n"
		);
	ft_printf(
		"Controls while running:\n"
		"  - Press 'i' to increase iterations.\n"
		"  - Press 'q', 'w', 'a', 's' to adjust Julia set parameters.\n"
		);
}
