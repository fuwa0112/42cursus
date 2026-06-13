/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:51:13 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/12 14:51:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "free_memory.h"

void	save_color(const char *token, t_color *dst)
{
	char	**rgb;

	rgb = ft_split_charset((char *)token, ",");
	dst->x = (unsigned char)ft_atoi(rgb[0]);
	dst->y = (unsigned char)ft_atoi(rgb[1]);
	dst->z = (unsigned char)ft_atoi(rgb[2]);
	free_arr(rgb);
}

void	save_vec4(const char *token, t_vec4 *dst)
{
	char	**coordinates;

	coordinates = ft_split_charset((char *)token, ",");
	dst->x = ft_atof(coordinates[0]);
	dst->y = ft_atof(coordinates[1]);
	dst->z = ft_atof(coordinates[2]);
	dst->w = 0.0;
	free_arr(coordinates);
}
