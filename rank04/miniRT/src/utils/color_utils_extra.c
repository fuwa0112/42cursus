/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:10:44 by lshein            #+#    #+#             */
/*   Updated: 2025/07/23 12:19:48 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	vec3_to_color(t_vec3 vec)
{
	t_color	out;

	out.r = fmin(vec.x * 255.0, 255.0);
	out.g = fmin(vec.y * 255.0, 255.0);
	out.b = fmin(vec.z * 255.0, 255.0);
	return (out);
}
