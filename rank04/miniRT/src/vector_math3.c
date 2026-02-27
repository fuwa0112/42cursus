/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:20 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/27 17:58:22 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "scene_elements.h"

float	v_length(const t_vec3f v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	v_length_squared(const t_vec3f v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
