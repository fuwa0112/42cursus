/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:14 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/27 17:58:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	clamp(const float x, const float min, const float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

float	degrees_to_rad(float degrees)
{
	return (degrees * (M_PI / 180.0));
}
