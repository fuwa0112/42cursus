/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:50:01 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/28 14:53:37 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	plane_inter(t_ray *ray, t_objects *plan, double *current)
{
	t_vec	p_dir;
	t_vec	ori;
	double	tmp;
	double	dis1;
	double	dis2;

	ori = ray->orig;
	p_dir = plan->n_cord;
	tmp = vec_dot(ray->dir, p_dir);
	if (tmp != 0)
	{
		dis1 = vec_dot(vec_sub(ori, plan->cord), p_dir);
		dis2 = -dis1 / tmp;
		if (dis2 < EPS)
			return (0);
		*current = dis2;
		return (1);
	}
	return (0);
}
