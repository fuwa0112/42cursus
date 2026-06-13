/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:51:13 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/28 14:53:37 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		free_data_andexit(data, NULL, NULL);
	return (0);
}

int	close_win(t_data *data)
{
	free_data_andexit(data, NULL, NULL);
	return (0);
}
