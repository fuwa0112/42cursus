/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:09 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/27 17:58:10 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "scene_elements.h"
#include "shapes.h"

void	rt_cleanup(t_parser *master)
{
	free(master->lights);
	free(master->camera);
	free(master->hittables->planes);
	free(master->hittables->spheres);
	free(master->hittables->cylinders);
}
