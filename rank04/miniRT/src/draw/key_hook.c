/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:54:09 by hakama            #+#    #+#             */
/*   Updated: 2026/04/27 14:57:15 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hook(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == 65307)
		close_window(env);
	return (0);
}
