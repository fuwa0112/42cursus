/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:24:28 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 00:24:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	instructions_display(void)
{
	ft_printf(
		"------------------- Available fractals -------------------\n\n"
		"  - Julia\n"
		"  - Mandelbrot\n"
		"  - Burning_ship\n\n");
	ft_printf(
		"Run the program like this in the terminal:\n\n"
		"  ./fract-ol <fractal name> [color] "
		"[real constant] [imaginary constant]\n\n"
		"(The last three parameters are optional for Julia sets. "
		"Color can be Origin, Red, Blue, Green, or Gray.)\n\n");
	ft_printf(
		"Controls while running:\n"
		"  - Press 'i' to increase iterations.\n"
		"  - Press 'q', 'w', 'a', 's' to adjust Julia set parameters.\n");
}
